(for i in trump_tweets_0?.csv;
do 
	cat $i | ./mapper.py;
done) | sort | ./reducer.py > output.txt
