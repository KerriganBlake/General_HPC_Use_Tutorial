SNP Activity
==============

You are a researcher interested in studying SNPs in the coding region of each human chromosome individually. You know that you want to use hg19 and snp146, and you are able to find the location full dataset (including all human chromosomes) through the downloads page of UCSC database. Since you will want to perform a lot of editing on this file, you decide to download it directly onto your university's HPC which has all the software you need. To do this, you run the following command: 

```
wget http://hgdownload.cse.ucsc.edu/goldenPath/hg38/database/snp146CodingDbSnp.txt.gz
```

Next, you notice that the file is compressed, so you unzip the file:

```
guzip snp146CodingDbSnp.txt.gz
```

Now, you need to understand the structure of the file since you've never seen this dataset before. To do so, you look at the first 10 lines using head:

```
head snp146CodingDbSnp.txt
```

You should see the following (without header labels):

| bin | chrom | chromStart | chromEnd | name | transcript | frame | alleleCount | funcCodes | alleles | codons | peptides
| :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| 585	| chr1 | 14397  | 14400	| rs756427959	| NR_024540	| n/a	| 1	| 45,	| -,	| n/a,	| n/a, |
| 585	| chr1 | 14397	| 14400	| rs756427959	| NR_046018 | 	n/a	| 1	| 45,	| -,	| n/a,	| n/a, |
| 585	| chr1 | 17358	| 17361	| rs749387668	| NR_024540	| n/a	| 1	| 45,	| -,	| n/a,	| n/a, |
| 585	| chr1 | 51972	| 51975	| rs546829777	| XR_948874	| n/a	| 1	| 45,	| -,	| n/a,	| n/a, |
| 585	| chr1 | 69115	| 69116	| rs757299236	| NM_001005484	| 2	| 2	| 8,42,	| G,A,	| GGT,GAT, | 	G,D, |
| 585	| chr1 | 69133	| 69134	| rs781394307	| NM_001005484	| 2	| 2	| 8,42,	| A,G,	| GAA,GGA, | 	E,G, |

Now, you want to remove all lines that start with n/a in the codons column since you are particularly interested in amino acid changes. To do this, you run the following command that checks the 11th column (codons) and removes lines starting with "n" and put it into a new file:

```
awk '$11 !~ /^n/ { print }' snp146CodingDbSnp.txt > no_na_snp146CodingDbSnp.txt 
```
* In this command, we check the 11th column ($11) for values that do NOT (!~) start with (/^..) n (..n/) and print them to a new file ('... { print }' ${file} > ${new_file}) using awk.

Next, you want to extract all of the data for chromosome 1 and 2 into seperate files. You decide to again use awk and check the 2nd columns for chr1 and chr2:

```
awk '$2 == "chr1" { print }' no_na_snp146CodingDbSnp.txt > chr1_no_na_snp146CodingDbSnp.txt
awk '$2 == "chr2" { print }' no_na_snp146CodingDbSnp.txt > chr2_no_na_snp146CodingDbSnp.txt
```

* In this command, we check the 2nd column ($2) for values exactly equal to chr1 ($2 == "chr1") and chr2 ($2 == "chr2") and print them to a new file ('... { print }' ${file} > ${new_file}) using awk.

At this point, you realize that you could have removed the na values and seperated the data into chromosomes with a single command using and (&&) with awk. Here is an example of that command:

```
awk '$2 == "chr2" && $11 !~ /^n/ { print }' snp146CodingDbSnp.txt > alt_chr2_no_na_snp146CodingDbSnp.txt
```

Now that you have chromosomes 1 and 2, you want to reformat the data for use with a program that requires the following tab-seperated format, with the data ordered by name in a logical numerical order (i.e. rs1, rs2,....rs10, rs11):

| name | chrom:chromStart-chromEnd | peptide1 | peptide2 | ... | 
| :---: | :---: | :---: | :---: | :---: |
| rs756427959	| chr1:14397-14400 | A | V | |
| rs756427959	| chr1:14397-14400| A | A | |

You decide to test this only on chromsome 1, and start by extracting the relevant columns into yet another file without sorting. To do this, you start by taking advantage of awk's print functionalities to move and reformat your columns as follows:

```
 awk '{print $5"\t"$2":"$3"-"$4"\t"$12 }' chr1_no_na_snp146CodingDbSnp.txt > unsorted_reformatted_chr1_snp146.txt
```

Now, you want to remove the final comma in your peptide column before substituting 
