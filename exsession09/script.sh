for i in trump_tweets_0?.csv
do 
	cat $i | ./mapper.py > map.txt
done

cat map.txt | sort | ./reducer.py > output.txt
