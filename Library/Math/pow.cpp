ll pow(ll a, ll b) {
    if (b == 0) return 1;
    if (b % 2) return a * pow(a, b - 1);
    return pow(a * a, b / 2);
}

//a^(-1)≡a^(p-2) (mod p) (but p is prime)
ll powMod(ll a, ll b, ll p) {
    if (b == 0) return 1;
    if (b % 2) return (a * powMod(a, b - 1, p)) % p;
    return powMod(a * a % p, b / 2, p);
}