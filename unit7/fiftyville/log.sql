-- Keep a log of any SQL queries you execute as you solve the mystery.

-- get the description of the crime
SELECT description FROM crime_scene_reports
WHERE year = 2020 AND month = 7 AND day = 28 AND street = "Chamberlin Street";
-- we learn that the theft was at 10:15 am at the Chamberlin Street courthouse. Interviews were conducted that day with three witnesses who were present at the time, each of their interview transcripts mentions the courthouse.
-- review the transcripts of the interviews
SELECT transcript FROM interviews
WHERE year = 2020 AND month = 7 AND day = 28;
-- 1st transcript - sometime within ten minutes of the theft, the thief got in a car in the courthouse parking lot and drove away - check security footage
-- 2nd transcript - earlier this morning, i was walking by the ATM on Fifer Street and saw the thief there withdrawing some money
-- 3rd transcript - as the thief was leaving the courthouse, they called someone who talked to them for less than a minute. in the call, i heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. the thief then asked the person on the other end of the phone to purchase the flight ticket
-- check security logs for liceense plate numbers of exiting cars
SELECT license_plate, activity, minute FROM courthouse_security_logs
WHERE year = 2020 AND month = 7 AND day = 28 AND hour = 10;
-- 5P2BI95, 94KL13X, 6P58WS2, 4328GD8, G412CB7, L93JTIZ, 322W7JE, 0NTHK55 are the license plate numbers that exited the courthouse within ten minutes of the theft
-- check the names of people with the license plates
SELECT name FROM people
WHERE license_plate = "5P2BI95" or license_plate = "94KL13X" or license_plate = "6P58WS2" or license_plate = "4328GD8" or license_plate = "G412CB7" or license_plate = "L93JTIZ" or license_plate = "322W7JE" or license_plate = "0NTHK55";
-- the names are Patrick, Amber, Elizabeth, Roger, Danielle, Russell, Evelyn, Ernest
--check the people who withdrew money at the ATM on Fifer Street earlier that morning
SELECT people.name FROM
people JOIN bank_accounts ON people.id = bank_accounts.person_id
JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
WHERE atm_transactions.year = 2020 AND atm_transactions.month = 7 AND atm_transactions.day = 28
AND atm_transactions.atm_location = "Fifer Street" AND atm_transactions.transaction_type = "withdraw";
-- The people are Ernest, Russell, Roy, Bobby, Elizabeth, Danielle, Madison, Victoria
--check the phone calls near the time of the theft that are less than a minute
SELECT caller, receiver FROM phone_calls
WHERE year = 2020 AND month = 7 AND day = 28 AND duration < 60;
--check the names of the callers
SELECT people.name, people.phone_number FROM people
JOIN phone_calls ON people.phone_number = phone_calls.caller
WHERE phone_calls.year = 2020 AND phone_calls.month = 7 AND phone_calls.day = 28 AND phone_calls.duration < 60;
--the names of the callers are Roger, Evelyn, Ernest, Evelyn, Madison, Russell, Kimberly, Bobby, Victoria
-- Russell and Ernest are now two main suspects
-- check the receiver of the phone calls
SELECT people.name, people.phone_number FROM people
JOIN phone_calls ON people.phone_number = phone_calls.receiver
WHERE phone_calls.year = 2020 AND phone_calls.month = 7 AND phone_calls.day = 28 AND phone_calls.duration < 60;
-- the names of the receivers are Jack, Larry, Berthold, Melissa, James, Philip, Jacqueline, Doris, Anna
--Berthold received Ernest's phone call and Philip received Russell's phone call
--find the airport name in Fiftyville
SELECT full_name FROM airports
WHERE city = "Fiftyville";
-- the airport name is Fiftyville Regional Airport
-- find the morning flights
SELECT flights.year, flights.month, flights.day, flights.hour, flights.minute, flights.origin_airport_id, flights.destination_airport_id, people.name FROM flights
JOIN airports ON flights.origin_airport_id = airports.id
JOIN passengers ON flights.id = passengers.flight_id
JOIN people ON passengers.passport_number = people.passport_number
WHERE airports.full_name = "Fiftyville Regional Airport" AND (people.name = "Ernest" or people.name = "Russell");
--Ernest flew at 8:20 to an airport id of 4 and Russell flew at 16:00 to an airport id of 6 on 7/29/2020
--Ernest is the thief because he flew out first thing in the morning
--Check the city Ernest flew to
SELECT airports.city FROM airports
WHERE airports.id = 4;
