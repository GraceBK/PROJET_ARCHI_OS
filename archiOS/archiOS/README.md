# Analyse de la hiérarchie mémoire de la machine

    lscpu
    lscpu | grep "cache"
    cat /proc/cpuinfo
    lsb_release -a
    uname -a

# CACHE
## 1) Cache de niveau L1

    tailleCache = 32

## 2) Cache de niveau L2

    tailleCache = 256

## 3) Cache de niveau L3

    tailleCache = 3072

## 1) Cache de niveau L1, L2 et L3

    tailleCache = une grande valeur


# BANDE PASSANTE

# CALIBRATOR

    cc calibrator [MHz] [size] [filename]