# Write your MySQL query statement below
SELECT tweet_id FROM Tweets where  
CHAR_LENGTH(content) > 15;