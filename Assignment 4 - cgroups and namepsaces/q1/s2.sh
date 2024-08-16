#!/bin/bash

function func {
    # Use as
    #   func "cgroup-name" "periods" "quota"

    mkdir /sys/fs/cgroup/cpu/$1;
    echo "Period,Quota,Shares:" $2 $3 $(cat /sys/fs/cgroup/cpu/$1/cpu.shares);
    echo $2 > /sys/fs/cgroup/cpu/$1/cpu.cfs_period_us;
    echo $3 > /sys/fs/cgroup/cpu/$1/cpu.cfs_quota_us;

    g++ a.cpp -o b.out;
    output=$(./b.out $1);
    echo $output;

    cat /sys/fs/cgroup/cpu/$1/cpu.stat;
    echo "cpuacct_usage" $(($(cat /sys/fs/cgroup/cpu/$1/cpuacct.usage)/1000000));

    rmdir /sys/fs/cgroup/cpu/$1;
    echo "";
}

period=500000

for perc in 100 90 80 70 60 55 50 45 40
do
    echo "-------- Quota:" $perc " --------"
    quota=$(($period * $perc / 100))
    func "cga41" $period $quota
done;
