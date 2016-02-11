# store the current directory
initial.dir<-getwd()
# change to the new directory
setwd("/home/aman/cs\ practice/")
# load the necessary libraries
library(nlme)
# set the output file
sink("output.out")
# load the dataset
# reading the data from file
d=read.table('output.txt', header=F, sep="\t", col.names=c("n","timet"));
# determining the max
max_y <- max(d);
# determinign colour
plot_colors <- c("blue","red");
# determining output
png(filename="figure.png", height=1000, width=1000);
# polting graph
plot(d$timet,d$n, type="o", col=plot_colors[1], ylim=c(0,max_y), axes=TRUE, ann=TRUE);
# flushing the output
dev.off();
# close the output file
sink()
# unload the libraries
detach("package:nlme")
# change back to the original directory
setwd(initial.dir)
