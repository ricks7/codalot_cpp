codalot
=======

Advanced algorithms for the kingdom

## Overview

Codalot is like [the Camelot of Arthurian legend](http://en.wikipedia.org/wiki/Camelot), except that it's about code, not camels...?

This project is a prototype that we're developing for a new game concept.  We think it has the potential to be *way* more fun than anything that's come before it.

## What it does

Here are the rules that have been implemented so far:

- There are exactly 6 knights in the castle and there will never be more.
- Time is measured in increments of 1 hour.
- During any given hour, each knight can be either in the training yard or in the tavern.
- A knight earns 1 stamina (STA) for each hour spent in the tavern.
- A knight earns 1 experience point (XP) and loses 1 STA for each hour spent in the training yard.
- If exactly 3 of the 6 knights earn 3 or more XP in a day, those 3 knights earn a bonus of 5 XP each.
- If exactly 5 of the 6 knights earn 3 or more XP in a day, those 5 knights earn a bonus of 10 XP each.
- If all 6 of the knights earn 3 or more XP in a day, they earn a bonus of 20 XP each.

All the application does right now is print out the total XP earned by all 6 knights in a 24 hour period based on a random placement of the knights each hour.  This at least proves that the system is working according to the rules if you step through a debugger.  We haven't had time yet to implement anything else - in fact, what you see so far was implemented by an intern, and nobody has even had a chance to look at the internals yet.

## Instructions

First, clone this repo so that you have a working copy with your own commit history.

This is now your code base - you own it.  That means you're allowed to do anything you want with it, and you should treat it as you would treat real code in a real workplace setting.  Pretend that you're in charge of technical direction for this product and answer to nobody but the product manager who's feeding you the rules that he wants implemented.  Nothing is off limits so long as you keep the code fully within this one repository.

Pretend that the product manager for codalot sends you one email each morning, in the given order, and that he comes to you with these requirements one at a time.  Show your work at each step by committing your changes to your repo with appropriate commit comments.  Feel free to use as many commits as you want, but there should be at least one per email - otherwise, how would we deploy your changes?

Here are the emails you receive:

1. "6 knights wasn't enough.  We need at least 12, so let's start there.  I might want more in the future.  Can you handle that?"
2. "We must have missed something in requirements analysis, because the knights are earning way too many XP, and I'm pretty sure it's because the last developer didn't implement this rule we talked about regarding stamina - knights shouldn't earn any XP for a given hour if they're trying to train in the yard with 0 stamina.  Can you check on that to see if it's implemented correctly?"
3. "Adding 6 more knights has made the game way more dynamic and fun, I think.  But now the bonus XP system feels broken - it wasn't meant to scale to 12 knights or more.  Got any good ideas?  Try to come up with a new bonus XP system and we'll talk later about it."
4. "I think we should have the knights earn no XP for the entire day if they would ever go below 0 stamina.  So 0 is okay, so long as they don't try to train any further after that."
5. "We're thinking about how this system would work across a larger number of days.  We want to be able to simulate a week, or two weeks, or a month, and then have the XP accumulated for that entire period.  All the other rules stay exactly the same - this is just a way for the game to run longer with the same group of knights and see how many XP they could earn over that time.  Can you show how that would work?"
6. "Okay, we have a really big change now.  I want to add King Arthur.  He should be just like any other knight, except I don't want his XP to be counted toward the total earned by all knights in a given time period - rather, I want his XP to be reported on its own.  Oh, but I *do* want him to count for the purposes of the bonus XP system.  Oh, one more thing: I want to add a new location that the knights can visit - a round table!  The round table has to be visited by a knight for at least 3 hours in any day for the knight to earn any XP for that day.  Can you get this done by lunch?"

## Criteria

We'll judge your submission on the basis of whether we would want to modify, debug, and maintain your code in a real work environment.  Pretty simple!  Again, you own this code, and it should reflect your best engineering abilities on every dimension.
