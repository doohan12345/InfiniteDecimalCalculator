int max(int a, int b) {
    // 만약 a가 b보다 작거나 같다면 b를 반환하고, 그렇지 않다면 a를 반환합니다.
    return (a <= b) ? b : a;
}

int min(int a, int b) {
    // 만약 a가 b보다 작거나 같다면 a를 반환하고, 그렇지 않다면 b를 반환합니다.
    return (a <= b) ? a : b;
}
