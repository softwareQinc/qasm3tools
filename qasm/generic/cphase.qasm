gate CX c, t {
  ctrl @ U(π, 0, π) c, t;
}
gate cphase(θ) a, b
{
  U(0, 0, θ / 2) a;
  CX a, b;
  U(0, 0, -θ / 2) b;
  CX a, b;
  U(0, 0, θ / 2) b;
}
qubit[2] q;
cphase(π / 2) q[0], q[1];
