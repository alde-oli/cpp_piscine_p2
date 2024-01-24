 [M, O, N, K, E, Y, P, U, Z, A, L, Q, C, I, V, B];

pair
[(M, O), (N, K), (E, Y), (P, U), (Z, A), (L, Q), (C, I), (V, B)];

sort
[(M, O), (K, N), (E, Y), (P, U), (A, Z), (L, Q), (C, I), (B, V)];

split
[M, K, E, P, A, L, C, B]  [O, N, Y, U, Z, Q, I, V];

pair
[(M, K), (E, P), (A, L), (C, B)]  [(O, N), (Y, U), (Z, Q), (I, V)];

sort
[(K, M), (E, P), (A, L), (B, C)]  [(N, O), (U, Y), (Q, Z), (I, V)];

split
[K, E, A, B] [M, P, L, C] [N, U, Q, I] [O, Y, Z, V];

pair
[(K, E), (A, B)] [(M, P), (L, C)] [(N, U), (Q, I)] [(O, Y), (Z, V)];

sort
[(E, K), (A, B)] [(M, P), (C, L)] [(N, U), (I, Q)] [(O, Y), (V, Z)];

split
[E, A] [K, B] [M, C] [P, L] [N, I] [U, Q] [O, V] [Y, Z];

sort
[A, E] [B, K] [C, M] [L, P] [I, N] [Q, U] [O, V] [Z, Y]

then we can merge them back together:
take the two sorted lists, and merge them into a single sorted lists by comparing the first elements of each list,
and taking the smaller one, and then repeating the process until both lists are empty.
[A, B, E, K] [C, L, M, P] [I, N, Q, U] [O, V, Y, Z];
repeat
[A, B, C, E, K, L, M, P] [I, N, O, Q, U, V, Y, Z];
repeat
[A, B, C, E, I, K, L, M, N, O, P, Q, U, V, Y, Z];
