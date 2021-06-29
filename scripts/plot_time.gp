reset
set xlabel 'F(n)'
set ylabel 'time (ns)'
set title 'Fibonacci runtime (iterative)'
set term png enhanced font 'Verdana,10'
set output 'plot_output.png'
set grid
plot [0:184][0:1200] \
'measure_time_list' using 1:2 with linespoints linewidth 2 title "kernel", \
'' using 1:3 with linespoints linewidth 2 title "user",  \
'' using 1:4 with linespoints linewidth 2 title "kernel\\\_to\\\_user"