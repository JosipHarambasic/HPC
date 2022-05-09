## Exercise 2
- We have a lot of information in the OutputPymapreduce.txt file, which is just the output
of the log after running ``pymapreduce.sh``. We can see the splits and reductions were made (Map input records=35371,
        Map output records=538568, Reduce input groups=47090, Reduce output records=47090) and much more.
- The output files that were generated are _SUCCESS and the part-00000 (contains wordcount results) files.
- By looking at the wc of output.txt and part-00000 we have a slight difference, I think this is because of the interpretation
of the emojis that can disturb some words.

``      47148   94308  642996 output.txt ``

``      47090   94192  642476 part-00000``
