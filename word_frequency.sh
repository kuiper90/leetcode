# https://leetcode.com/problems/word-frequency/

# read from the file and output the word frequency list to standard output. 
# convert each space into newline
# sort and count the nr of times each line occurred along with the line 
# the sort numerically putting lines with greater key values first
# and print first the count and second the counted
cat words.txt | tr -s ' ' '\n' | sort | uniq -c | sort -rn | awk '{print $2 " " $1}'