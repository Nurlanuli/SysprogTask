#! /bin/bash
sum=$(cat log.txt | grep -e 'HTTP/1.1" 4' -e 'HTTP/1.0" 4' | wc -l);
cat log.txt | grep -e 'HTTP/1.1" 4' -e 'HTTP/1.0" 4'| cut -f7 -d" " | sort | uniq -c | sort -k1 -r -n | head | cat -n | awk '{print $1 ". " $3 " - " $2 " - " $2*100/"'$sum'" "%"}'

