void compose_rotations(){
    newq[0] = cos(sqrt(pow(fabs(v[0]),2) + pow(fabs(v[1]),2) + pow(fabs(v[2]),2))/2.)*q[0] - (q[1]*sin(sqrt(pow(fabs(v[0]),2) + pow(fabs(v[1]),2) + pow(fabs(v[2]),2))/2.)*v[0])/sqrt(pow(fabs(v[0]),2) + pow(fabs(v[1]),2) + pow(fabs(v[2]),2)) - (q[2]*sin(sqrt(pow(fabs(v[0]),2) + pow(fabs(v[1]),2) + pow(fabs(v[2]),2))/2.)*v[1])/sqrt(pow(fabs(v[0]),2) + pow(fabs(v[1]),2) + pow(fabs(v[2]),2)) - (q[3]*sin(sqrt(pow(fabs(v[0]),2) + pow(fabs(v[1]),2) + pow(fabs(v[2]),2))/2.)*v[2])/sqrt(pow(fabs(v[0]),2) + pow(fabs(v[1]),2) + pow(fabs(v[2]),2));
    newq[1] = cos(sqrt(pow(fabs(v[0]),2) + pow(fabs(v[1]),2) + pow(fabs(v[2]),2))/2.)*q[1] + (q[0]*sin(sqrt(pow(fabs(v[0]),2) + pow(fabs(v[1]),2) + pow(fabs(v[2]),2))/2.)*v[0])/sqrt(pow(fabs(v[0]),2) + pow(fabs(v[1]),2) + pow(fabs(v[2]),2)) + (q[3]*sin(sqrt(pow(fabs(v[0]),2) + pow(fabs(v[1]),2) + pow(fabs(v[2]),2))/2.)*v[1])/sqrt(pow(fabs(v[0]),2) + pow(fabs(v[1]),2) + pow(fabs(v[2]),2)) - (q[2]*sin(sqrt(pow(fabs(v[0]),2) + pow(fabs(v[1]),2) + pow(fabs(v[2]),2))/2.)*v[2])/sqrt(pow(fabs(v[0]),2) + pow(fabs(v[1]),2) + pow(fabs(v[2]),2));
    newq[2] = cos(sqrt(pow(fabs(v[0]),2) + pow(fabs(v[1]),2) + pow(fabs(v[2]),2))/2.)*q[2] - (q[3]*sin(sqrt(pow(fabs(v[0]),2) + pow(fabs(v[1]),2) + pow(fabs(v[2]),2))/2.)*v[0])/sqrt(pow(fabs(v[0]),2) + pow(fabs(v[1]),2) + pow(fabs(v[2]),2)) + (q[0]*sin(sqrt(pow(fabs(v[0]),2) + pow(fabs(v[1]),2) + pow(fabs(v[2]),2))/2.)*v[1])/sqrt(pow(fabs(v[0]),2) + pow(fabs(v[1]),2) + pow(fabs(v[2]),2)) + (q[1]*sin(sqrt(pow(fabs(v[0]),2) + pow(fabs(v[1]),2) + pow(fabs(v[2]),2))/2.)*v[2])/sqrt(pow(fabs(v[0]),2) + pow(fabs(v[1]),2) + pow(fabs(v[2]),2));
    newq[3] = cos(sqrt(pow(fabs(v[0]),2) + pow(fabs(v[1]),2) + pow(fabs(v[2]),2))/2.)*q[3] + (q[2]*sin(sqrt(pow(fabs(v[0]),2) + pow(fabs(v[1]),2) + pow(fabs(v[2]),2))/2.)*v[0])/sqrt(pow(fabs(v[0]),2) + pow(fabs(v[1]),2) + pow(fabs(v[2]),2)) - (q[1]*sin(sqrt(pow(fabs(v[0]),2) + pow(fabs(v[1]),2) + pow(fabs(v[2]),2))/2.)*v[1])/sqrt(pow(fabs(v[0]),2) + pow(fabs(v[1]),2) + pow(fabs(v[2]),2)) + (q[0]*sin(sqrt(pow(fabs(v[0]),2) + pow(fabs(v[1]),2) + pow(fabs(v[2]),2))/2.)*v[2])/sqrt(pow(fabs(v[0]),2) + pow(fabs(v[1]),2) + pow(fabs(v[2]),2));
}

void rotate_point(){
    p[0] = q[2]*(p0[2]*q[0] + p0[1]*q[1] - p0[0]*q[2]) - q[3]*(p0[1]*q[0] - p0[2]*q[1] + p0[0]*q[3]) + q[0]*(p0[0]*q[0] + p0[2]*q[2] - p0[1]*q[3]) - q[1]*(-(p0[0]*q[1]) - p0[1]*q[2] - p0[2]*q[3]);
    p[1] = -(q[1]*(p0[2]*q[0] + p0[1]*q[1] - p0[0]*q[2])) + q[0]*(p0[1]*q[0] - p0[2]*q[1] + p0[0]*q[3]) + q[3]*(p0[0]*q[0] + p0[2]*q[2] - p0[1]*q[3]) - q[2]*(-(p0[0]*q[1]) - p0[1]*q[2] - p0[2]*q[3]);
    p[2] = q[0]*(p0[2]*q[0] + p0[1]*q[1] - p0[0]*q[2]) + q[1]*(p0[1]*q[0] - p0[2]*q[1] + p0[0]*q[3]) - q[2]*(p0[0]*q[0] + p0[2]*q[2] - p0[1]*q[3]) - q[3]*(-(p0[0]*q[1]) - p0[1]*q[2] - p0[2]*q[3]);
}