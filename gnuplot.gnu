reset
set terminal png
set output 'result_time.png'
set key below
set xrang [0:3000]
set yrang [0:3000]
plot "donnees.dat" using 0:2 with line
