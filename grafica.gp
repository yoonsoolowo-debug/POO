set xrange[0:7]
set yrange[-2.5:2.5]

set xtics 0.5
set ytics 0.5

set grid

plot 2*sin(3*x+0.5), sin(x) using 1:2 with linespoints
