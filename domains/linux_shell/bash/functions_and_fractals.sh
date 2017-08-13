#!/bin/bash

read g_n

#g_rows=63
g_cols=100

function blank_line {
    for underscores in {1..100}; do
        printf "_"
    done
    printf "\n"
}

function print_branches {
    local spacing=$1

}

function print_trunk {
    local cols=$1
    local print1=$2

    for c in $(seq 1 $(($cols - 1))); do
        printf "_"
    done

    if [ $print1 -eq 1 ]; then
        printf "1"
    else
        printf "_"
    fi
}

function print_white_space {
    local len=$1
    for ws in $(seq 1 $len); do
        printf "_"
    done
}

function tree {
    local p=$1
    local n=$2
    local rows=$3
    local spacing=$4

    if [ $p -eq 0 ]; then
        return 0 # all done
    fi

    if [ $p -eq 5 ]; then
        print_white_space 100
        printf "\n"
        if [ $n -eq $p ]; then
            print_white_space 18
            printf "1"
            for t in {2..32}; do
                print_trunk 2 1
            done
            print_white_space 19
        else
            print_white_space 100
        fi
        printf "\n"
    fi

    echo "$p $n $rows $spacing"
    if [ $p -eq $n ]; then

        for r in $(seq 1 $(($rows/2))); do
            print_branches
        done

        for r in $(seq 1 $(($rows/2))); do
            print_white_space 18
            local trunks=$(((64/($spacing*2))-1))
            print_trunk $spacing 1
            if [ $trunks -gt 0 ]; then
                for t in $(seq 1 $trunks); do
                    print_trunk $(($spacing*2)) 1
                done
            fi
            print_trunk $spacing 0
            print_white_space 18
            printf "\n"
        done

    else
        for r in $(seq 1 $rows); do
            blank_line
        done
    fi

    local n_next=$n
    if [ $p -eq $n ]; then
        n_next=$(($n-1))
    fi
    tree $(($p-1)) $n_next $(($rows*2)) $(($spacing*2))
}

tree 5 $g_n 2 2

