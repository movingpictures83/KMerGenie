# Trimmomatic
# Language: C++
# Input: TXT
# Output: Prefix
# Tested with: PluMA 1.1, GCC 4.8.4
# Dependencies: KMerGenie 1.7051

PluMA plugin to estimate an optimal K-Mer size for genome assembly
given files for forward and reverse reads, a lower and upper bound,
and step size.

The plugin accepts as input a TXT file of tab-delimited keyword value pairs,
with the following keywords:

files: TXT file listing the names of forward and reverse FASTQ
low: lower bound
high: upper bound
step: stepsize

The plugin will then try values from low to high, in increments of the step
size.

Histograms will be generated for every candidate k-mer length, prefixed
by the user-specified output prefix.

