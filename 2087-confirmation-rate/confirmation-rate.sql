SELECT s.user_id,
       Round(avg(if(action='confirmed',1,0)),2) AS confirmation_rate
FROM Signups s
LEFT JOIN confirmations c ON s.user_id = c.user_id
GROUP BY s.user_id;
