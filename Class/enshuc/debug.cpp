/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * This program demonstrates the use of the merge sort algorithm.  For
 * more information about this and other sorting algorithms, see
 * http://linux.wku.edu/~lamonml/kb.html
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/wait.h>
#include <sys/time.h>

#define BUFSIZE 1024
#define VALUE_RANGE 1000000000

int numitems;
int numprocs;

void mergeSort(int numbers[], int temp[], int array_size);
void m_sort(int numbers[], int temp[], int left, int right, int proc);
void merge(int numbers[], int temp[], int left, int mid, int right);

int *numbers;
int *temp;

char buf[BUFSIZE];
int sid;
int **fd;

void sem_wait(int sid, int num) {
  struct sembuf sb;
  sb.sem_num = num;
  sb.sem_op = -1;
  sb.sem_flg = 0;
  if (semop(sid, &sb, 1) == -1) {
    perror("sem_wait semop error.");
    exit(1);
  }
}

void sem_signal(int sid, int num) {
  struct sembuf sb;
  sb.sem_num = num;
  sb.sem_op = 1;
  sb.sem_flg = 0;
  if (semop(sid, &sb, 1) == -1) {
    perror("sem_signal semop error.");
    exit(1);
  }
}

int main(int argc, char *argv[])
{
  int i;
  key_t key;
  /*  struct timeval start, tv;
  gettimeofday(&start, NULL);
  gettimeofday(&tv, NULL);
  tv -= start
  printf("%ld.%lu\n", tv.tv_sec, tv.tv_usec);
  */
  numitems = 10;
  numprocs = 0;
  if (argc >= 2)
    numitems = atoi(argv[1]);
  if (argc >= 3)
    numprocs = atoi(argv[2]);
  
  numbers = (int *)malloc(sizeof(int) * numitems);
  temp = (int *)malloc(sizeof(int) * numitems);
  fd = (int **)malloc(sizeof(int *) * numprocs);
  for (i = 0; i < numprocs; i++) {
    fd[i] = (int *)malloc(sizeof(int) * 2);
  }

  if ((key = ftok(".", 1)) == -1) {
    fprintf(stderr, "ftok path does not exist.\n");
    exit(1);
  }
  if (numprocs > 0 && (sid = semget(key, numprocs, 0666 | IPC_CREAT)) == -1) {
    perror("semget error.");
    exit(1);
  }
  for (i = 0; i < numprocs; i++) {
    semctl(sid, i, SETVAL, 1);
    if (pipe(fd[i]) == -1) {
      perror("pipe failed.");
      exit(1);
    }
  }

  //seed random number generator
  srand(getpid());

  //fill array with random integers
  for (i = 0; i < numitems; i++) {
     numbers[i] = rand();
     //printf("%d\n", numbers[i]);
  }

  //perform merge sort on array
  mergeSort(numbers, temp, numitems);

  printf("Done with sort.\n");

  for (i = 0; i < numitems; i++) {
    //printf("%i\n", numbers[i]);
  }

  for (i = 0; i < numprocs; i++) {
    free(fd[i]);
    semctl(sid, i, IPC_RMID);
  }
  free(fd);
  free(numbers);
  free(temp);
  return 0;
}


void mergeSort(int numbers[], int temp[], int array_size)
{
  m_sort(numbers, temp, 0, array_size - 1, 0);
}

void m_sort(int numbers[], int temp[], int left, int right, int proc)
{
  int i, mid, pid, status, nbytes;

  if (right > left)
  {
    mid = (right + left) / 2;

    if (proc < numprocs) { // fork ok
      if ((pid = fork()) == -1) {
	perror("fork failed.");
	exit(1);
      }
      if (pid == 0) { // child
	close(fd[proc][0]);
	m_sort(numbers, temp, left, mid, proc * 2 + 1);
	for (i = left; i <= mid; i++) {
        memset(buf, 0, sizeof(buf));
	  sprintf(buf, "%d", numbers[i]);
	  sem_wait(sid, proc);
	  write(fd[proc][1], buf, strlen(buf));
	}
	exit(0);
      }
      else { // parent
	close(fd[proc][1]);
	m_sort(numbers, temp, mid+1, right, proc * 2 + 2);
	for (i = left; i <= mid; i++) {
        
        memset(buf, 0, sizeof(buf));
	  nbytes = read(fd[proc][0], buf, sizeof(buf));
	  sem_signal(sid, proc);
	  numbers[i] = atoi(buf);
	}
	waitpid(pid, &status, 0);
      }
    }
    else { // fork no
      m_sort(numbers, temp, left, mid, proc * 2 + 1);
      m_sort(numbers, temp, mid+1, right, proc * 2 + 2);
    }

    merge(numbers, temp, left, mid+1, right);
  }
}


void merge(int numbers[], int temp[], int left, int mid, int right)
{
  int i, left_end, num_elements, tmp_pos;

  left_end = mid - 1;
  tmp_pos = left;
  num_elements = right - left + 1;

  while ((left <= left_end) && (mid <= right))
  {
    if (numbers[left] <= numbers[mid])
    {
      temp[tmp_pos] = numbers[left];
      tmp_pos = tmp_pos + 1;
      left = left +1;
    }
    else
    {
      temp[tmp_pos] = numbers[mid];
      tmp_pos = tmp_pos + 1;
      mid = mid + 1;
    }
  }

  while (left <= left_end)
  {
    temp[tmp_pos] = numbers[left];
    left = left + 1;
    tmp_pos = tmp_pos + 1;
  }
  while (mid <= right)
  {
    temp[tmp_pos] = numbers[mid];
    mid = mid + 1;
    tmp_pos = tmp_pos + 1;
  }

  for (i=0; i <= num_elements; i++)
  {
    numbers[right] = temp[right];
    right = right - 1;
  }
}
