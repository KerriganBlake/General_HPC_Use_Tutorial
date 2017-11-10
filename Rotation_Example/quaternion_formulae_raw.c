void compose_rotations(){
    newq(0) == Cos(Sqrt(Power(Abs(v(0)),2) + Power(Abs(v(1)),2) + Power(Abs(v(2)),2))/2.)*q(0) - (q(1)*Sin(Sqrt(Power(Abs(v(0)),2) + Power(Abs(v(1)),2) + Power(Abs(v(2)),2))/2.)*v(0))/Sqrt(Power(Abs(v(0)),2) + Power(Abs(v(1)),2) + Power(Abs(v(2)),2)) - (q(2)*Sin(Sqrt(Power(Abs(v(0)),2) + Power(Abs(v(1)),2) + Power(Abs(v(2)),2))/2.)*v(1))/Sqrt(Power(Abs(v(0)),2) + Power(Abs(v(1)),2) + Power(Abs(v(2)),2)) - (q(3)*Sin(Sqrt(Power(Abs(v(0)),2) + Power(Abs(v(1)),2) + Power(Abs(v(2)),2))/2.)*v(2))/Sqrt(Power(Abs(v(0)),2) + Power(Abs(v(1)),2) + Power(Abs(v(2)),2));
    newq(1) == Cos(Sqrt(Power(Abs(v(0)),2) + Power(Abs(v(1)),2) + Power(Abs(v(2)),2))/2.)*q(1) + (q(0)*Sin(Sqrt(Power(Abs(v(0)),2) + Power(Abs(v(1)),2) + Power(Abs(v(2)),2))/2.)*v(0))/Sqrt(Power(Abs(v(0)),2) + Power(Abs(v(1)),2) + Power(Abs(v(2)),2)) + (q(3)*Sin(Sqrt(Power(Abs(v(0)),2) + Power(Abs(v(1)),2) + Power(Abs(v(2)),2))/2.)*v(1))/Sqrt(Power(Abs(v(0)),2) + Power(Abs(v(1)),2) + Power(Abs(v(2)),2)) - (q(2)*Sin(Sqrt(Power(Abs(v(0)),2) + Power(Abs(v(1)),2) + Power(Abs(v(2)),2))/2.)*v(2))/Sqrt(Power(Abs(v(0)),2) + Power(Abs(v(1)),2) + Power(Abs(v(2)),2));
    newq(2) == Cos(Sqrt(Power(Abs(v(0)),2) + Power(Abs(v(1)),2) + Power(Abs(v(2)),2))/2.)*q(2) - (q(3)*Sin(Sqrt(Power(Abs(v(0)),2) + Power(Abs(v(1)),2) + Power(Abs(v(2)),2))/2.)*v(0))/Sqrt(Power(Abs(v(0)),2) + Power(Abs(v(1)),2) + Power(Abs(v(2)),2)) + (q(0)*Sin(Sqrt(Power(Abs(v(0)),2) + Power(Abs(v(1)),2) + Power(Abs(v(2)),2))/2.)*v(1))/Sqrt(Power(Abs(v(0)),2) + Power(Abs(v(1)),2) + Power(Abs(v(2)),2)) + (q(1)*Sin(Sqrt(Power(Abs(v(0)),2) + Power(Abs(v(1)),2) + Power(Abs(v(2)),2))/2.)*v(2))/Sqrt(Power(Abs(v(0)),2) + Power(Abs(v(1)),2) + Power(Abs(v(2)),2));
    newq(3) == Cos(Sqrt(Power(Abs(v(0)),2) + Power(Abs(v(1)),2) + Power(Abs(v(2)),2))/2.)*q(3) + (q(2)*Sin(Sqrt(Power(Abs(v(0)),2) + Power(Abs(v(1)),2) + Power(Abs(v(2)),2))/2.)*v(0))/Sqrt(Power(Abs(v(0)),2) + Power(Abs(v(1)),2) + Power(Abs(v(2)),2)) - (q(1)*Sin(Sqrt(Power(Abs(v(0)),2) + Power(Abs(v(1)),2) + Power(Abs(v(2)),2))/2.)*v(1))/Sqrt(Power(Abs(v(0)),2) + Power(Abs(v(1)),2) + Power(Abs(v(2)),2)) + (q(0)*Sin(Sqrt(Power(Abs(v(0)),2) + Power(Abs(v(1)),2) + Power(Abs(v(2)),2))/2.)*v(2))/Sqrt(Power(Abs(v(0)),2) + Power(Abs(v(1)),2) + Power(Abs(v(2)),2));
}

void rotate_point(){
    p(0) == q(2)*(p0(2)*q(0) + p0(1)*q(1) - p0(0)*q(2)) - q(3)*(p0(1)*q(0) - p0(2)*q(1) + p0(0)*q(3)) + q(0)*(p0(0)*q(0) + p0(2)*q(2) - p0(1)*q(3)) - q(1)*(-(p0(0)*q(1)) - p0(1)*q(2) - p0(2)*q(3));
    p(1) == -(q(1)*(p0(2)*q(0) + p0(1)*q(1) - p0(0)*q(2))) + q(0)*(p0(1)*q(0) - p0(2)*q(1) + p0(0)*q(3)) + q(3)*(p0(0)*q(0) + p0(2)*q(2) - p0(1)*q(3)) - q(2)*(-(p0(0)*q(1)) - p0(1)*q(2) - p0(2)*q(3));
    p(2) == q(0)*(p0(2)*q(0) + p0(1)*q(1) - p0(0)*q(2)) + q(1)*(p0(1)*q(0) - p0(2)*q(1) + p0(0)*q(3)) - q(2)*(p0(0)*q(0) + p0(2)*q(2) - p0(1)*q(3)) - q(3)*(-(p0(0)*q(1)) - p0(1)*q(2) - p0(2)*q(3));
}