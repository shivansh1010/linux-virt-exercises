#!/bin/bash

function func {
    # Use as
    #   func "periods" "quota"

    mkdir /sys/fs/cgroup/cpu/cga4;
    echo $1 > /sys/fs/cgroup/cpu/cga4/cpu.cfs_period_us;
    echo $2 > /sys/fs/cgroup/cpu/cga4/cpu.cfs_quota_us;
    echo "Period,Quota,Shares:" $(cat /sys/fs/cgroup/cpu/cga4/cpu.cfs_period_us) $(cat /sys/fs/cgroup/cpu/cga4/cpu.cfs_quota_us) $(cat /sys/fs/cgroup/cpu/cga4/cpu.shares);

    # g++ b.cpp;
    output=$(./fivepid);
    echo $output;

    # cat /sys/fs/cgroup/cpu/cga4/cpu.stat;
    # echo "cpuacct_usage" $(($(cat /sys/fs/cgroup/cpu/cga4/cpuacct.usage)/1000000));

    rmdir /sys/fs/cgroup/cpu/cga4;
    echo "";
}


# func 100000 100000;

g++ -static b.cpp;
gcc fivepid.c -o fivepid;

period=100000
for perc in 100 90 80 70 60 55 50 45 40
do
    echo "-------- Quota:" $perc " --------"
    quota=$(($period * $perc / 100))
    func $period $quota
done;
