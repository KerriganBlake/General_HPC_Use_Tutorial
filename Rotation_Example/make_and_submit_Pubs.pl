#!/usr/bin/perl
# creates a number of job execution lines for submission to pbs

#define directory name to find executable and write to
my $dir_name = "HPC_use_test";
#base name for HPC (needs to be short)
my $hpc_name = "test";

system "mkdir /pub/mbovyn/$dir_name/pubs";
system "mkdir /pub/mbovyn/$dir_name/logs";

#define begining values
my $ctr=1;
my $max=10;

#loop until values have reached their max
while ( $ctr <= $max )
{
    #hpc run name
    my $hpc_instance_name = $hpc_name . "." . $ctr;
    #pub file name
    my $file_name=$hpc_instance_name . ".pub";

    #open file for writing and print the following
    open (FOOD, ">pubs/$file_name" );
    print FOOD << "EOF";
#!/bin/bash
#\$ -N $hpc_instance_name
#\$ -q bio,abio,free64,pub64
#\$ -ckpt blcr
#\$ -e logs/$hpc_instance_name.err
#\$ -o logs/$hpc_instance_name.log

cd /pub/mbovyn/$dir_name

echo Running on host `hostname`
echo Time is `date`
echo Directory is `pwd`

# Run executable
./rotation.x

echo Finished at `date`

EOF
    close FOOD;
    #done writing

    #submit job
    system "qsub pubs/$file_name";

    #increment counter
    $ctr++;
}
