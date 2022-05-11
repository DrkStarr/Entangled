

!---------------------------------------------------------------------------
!	HelpRoutines.h, by Emily Short (emshort@mindspring.com)
!	Version 1.0
!	8/16/02
!
!	Being a file of straightforward routines that will make your game print
!	wodges and wodges of text about IF playing.
!
!	Some portions based on paraphrase of instructional text by
!	Stephen Granade.
!---------------------------------------------------------------------------
!
!	RIGHTS:
!
!	This library file may be treated as public domain.  It may be
!	used in source with or without credit to the original author.  It may be
!	modified at the user's discretion.  It may be freely redistributed.
!	The textual content of the routines may be lifted from their context
!	and reused elsewhere.
!
!
!	INSTALLATION:
!
!	Include "HelpRoutines" in your gamefile.
!
!
!	CONTENTS:
!
!	-- Three basic formatting routines for doing bold and italic text
!		and for awaiting a keypress.  (The only reason to define these
!		is to provide z-code/Glulx flexibility.)
!
!	-- LongIntro.  A description of IF, which prints both of
!		-- BasicBrief.  A quick description of IF in the abstract
!		-- BasicIntro.  A somewhat longer description of same, discuss
!
!	-- ExplainPrompt.  What a prompt is.
!	-- StartingInstructions.  Suggests that the player look, examine items,
!			and check his inventory.
!	-- StuckInstructions.  A list of tips for a player in trouble
!
!	-- AllCommunication.  Prints all of the following:
!		-- Communication.  Basic instructions on how to form valid commands.
!		-- OnMovement
!		-- OnObjects
!		-- OnNPCs, which will also call one of
!			-- AskTellNPC (Define NPC_ASKTELL before including this file)
!			-- MenuNPC (Define NPC_MENU before including this file)
!			-- TalkToNPC (Define NPC_TALKTO before including this file)
!			-- TopicMenuNPC (Define NPC_TOPIC before including this file)
!		-- MetaCommands.  Introduces SAVE, QUIT, RESTART, RESTORE, UNDO.
!
!	-- StandardVerbs.  A list of standard verbs.  Self-adjusting to reflect
!	    the instructions about NPCS; it will list SCORE only if you have a MAX_SCORE
!		greater than 0, and the OBJECTS/PLACES commands only if you have not defined
!		NO_PLACES.
!	-- Abbreviations.  A list of abbreviations and their meanings.
!
!	-- OnlineHelp.  How to find online IF manuals.
!	-- MoreGames.  How to find more IF.
!
!	SEE ALSO:
!		-- SampleTranscript.h: contains several sample transcripts formatted
!			for inclusion in IF games.
!
!	CAVEAT
!
!	Note that in some cases this material may be incorrect for your game.
!	You are advised to read the resulting text and determine whether it suits
!	your ends.
!
!---------------------------------------------------------------------------


system_file;


!---------------------------------------------------------------------------
! Special effects -- bold-texting and pauses for display purposes
!---------------------------------------------------------------------------

#ifdef TARGET_GLULX;
[ ES_Pause i;
	i = KeyCharPrimitive();
	if (i=='q') rtrue;
	rfalse;
];
#ifnot;
[ ES_Pause i;
	@read_char 1 i;
	if (i == 'q') rtrue;
	rfalse;
];
#endif;

#ifdef TARGET_GLULX;
[ ESB str;	! print something in bold
	if (str==0) rfalse;
	glk_set_style(style_Input);
	print (string) str;
	glk_set_style(style_Normal);
	rtrue;
];
#ifnot;
[ ESB str;	! print something in bold
	if (str==0) rfalse;
	style bold;
	print (string) str;
	style roman;
	rtrue;
];
#endif;

#ifdef TARGET_GLULX;
[ ESI str;	! print something in italics
	if (str==0) rfalse;
	glk_set_style(style_Emphasized);
	print (string) str;
	glk_set_style(style_Normal);
	rtrue;
];
#ifnot;
[ ESI str;	! print something in italics
	if (str==0) rfalse;
	style underline;
	print (string) str;
	style roman;
	rtrue;
];
#endif;



!---------------------------------------------------------------------------
! Introductions
!---------------------------------------------------------------------------

[ LongIntro;
	BasicBrief();
	new_line;
	BasicIntro();
];

[ BasicBrief;
	print (ESI) "[These notes are lengthy, so the game will periodically
		pause while printing them. To stop the instructions mid-flow, press
		Q at a pause; to continue, press any other key.]^^";
	print (ESB) "INTERACTIVE FICTION^";
	print "The game you are playing is a work of Interactive Fiction. In interactive fiction
		you play the main character of a story. You type commands
		which determine the actions of the character and the flow of the plot. Some IF
		games include graphics, but most do not: the imagery is provided courtesy of your
		imagination. On the other hand, there's a wide range of action available:
		whereas in other games you may be restricted to shooting, movement, or searching
		items you can click on with a mouse, IF allows you a wide range of verbs.^";
];

[ BasicIntro;
	if (ES_Pause()) jump end;
	print "There are various kinds of IF in the world. Some of them put more
		emphasis on solving puzzles; some want to move you through a coherent plot
		of some kind; some want to offer you something to explore.^^";
	print "In games with a lot of challenging puzzles, you can expect to spend a fair
		amount of time wandering around trying to figure out what you should do
		next; this is part of the fun. (If you like that sort of thing, anyway.)
		When you start a game, you can usually get a sense fairly early on of what
		kind of game it is and what the author expects you to do. Read the
		opening text carefully: it may tell you things about the character you are
		playing, your goals within the game, and so on.^^";
	print "If the game tells you to type ABOUT or INFO the first time you play, you
		should always do so: this information may include special commands or
		other material without which you won't be able to finish. This is like
		the game manual in a commercial game, so don't ignore it.^^";
	if (ES_Pause()) jump end;
	print (ESB) "HOW THE WORLD IS ASSEMBLED^^";
	print "Space: Most IF games are set in a world made up of rooms without internal
		division. Movement between rooms is possible; movement within a room does
		not always amount to anything. >WALK OVER TO THE DESK is rarely a useful
		sort of command. On the other hand, if something is described
		as being high or out of reach, it is sometimes relevant to stand on an
		object to increase your height. This kind of activity tends to be
		important only if prompted by the game text.^^";
	print "Containment: One thing that IF does tend to model thoroughly is
		containment. Is something in or on something else? The game keeps track
		of this, and many puzzles have to do with where things are -- in the
		player's possession, lying on the floor of the room, on a table, in a box,
		etc.^^";
	if (ES_Pause()) jump end;
	print "Types of Action: Most of the actions you can perform in the world of IF
		are brief and specific. >WALK WEST or >OPEN DOOR are likely to be
		provided. >TAKE A JOURNEY or >BUILD A TABLE are not. Things like >GO TO
		THE HOTEL are on the borderline: some games allow them, but most do not.
		In general, abstract, multi-stage behavior usually has to be broken down
		in order for the game to understand it.^^";
	print "Other Characters: Other characters in IF games are sometimes rather
		limited. On the other hand, there are also games in which character
		interaction is the main point of the game. You should be able to get a
		feel early on for the characters -- if they seem to respond to a lot of
		questions, remember what they're told, move around on their own, etc.,
		then they may be fairly important. If they have a lot of stock responses
		and don't seem to have been the game designer's main concern, then they
		are most likely present either as local color or to provide the solution
		to a specific puzzle or set of puzzles. Characters in very
		puzzle-oriented games often have to be bribed, threatened, or cajoled into
		doing something that the player cannot do -- giving up a piece of
		information or an object, reaching something high, allowing the player
		into a restricted area, and so on.^";
	if (ES_Pause()) jump end;
	rtrue;

	.end;
	"Good Luck!";
];


!---------------------------------------------------------------------------
! Starting Instructions, Stuck Instructions
!---------------------------------------------------------------------------

[ StartingInstructions;
	print (ESB) "GETTING STARTED^";
	print "The first thing you want to do when starting a game is acquaint yourself
		with your surroundings and get a sense of your goal. To this end, you should:^^";
	print (ESB) "Read the introductory text carefully.  ", "Sometimes it contains clues.^";
	print (ESB) "Look at the room description.  ", "Get an idea of what sort of
		place you're in. Usually the description will tell you two important things:
		where the exits from the room are, and what the objects are that you can
		interact with. Type LOOK if you want to see the room description again.^";
	print (ESB) "Look at the things in the room.  ", "Individual descriptions of items
		can help you out.^";
	print (ESB) "Examine yourself.  ", "Information about your character may be
		important.^";
	if (ES_Pause()) jump end;
	print (ESB) "TAKE INVENTORY.  ", "Sometimes you'll be holding something important.^";
	.end;
	print (ESB) "Explore.  ", "Move from room to room, and check out every location
		available.^";
];

[ StuckInstructions;
	print (ESB) "Explore.  ", "Examine every object mentioned in room descriptions, and
		everything in your inventory. Examine yourself, too.
		Look inside all closed containers. Open
		all doors and go through them. If anything is locked, that's probably a
		puzzle, and you should try to get it unlocked.^^";
	print (ESB) "Try out all your senses.  ", "If the game mentions an interesting
		texture, odor, or sound, try SMELLing, TOUCHing, LISTENing, etc.^^";
	if (ES_Pause()) jump end;
	print (ESB) "Be thorough.  ", "If you *still* can't figure out what to do, try opening
		windows, looking under beds, etc. Sometimes objects are well-hidden.^^";
	print (ESB) "Reread.  ", "Look back at things you've already seen; sometimes this will
		trigger an idea you hadn't thought of.^^";
	print (ESB) "Take hints from the prose of the game.  ",
		"Things that are described in great
		detail are probably more important than things that are given one-liners.
		Play with those objects. If a machine is described as having component
		parts, look at the parts, and try manipulating them.  Likewise, notice
		the verbs that the game itself uses. Try using those yourself. Games
		often include special verbs -- the names of magic spells, or other special
		commands. There's no harm in attempting something if the game mentions
		it.^^";
	if (ES_Pause()) jump end;
	print (ESB) "Rephrase.  ",
		"If you have something in mind that you want to do, but can't
		get the game to respond, try alternative wordings. Often synonyms are
		provided. Game designers usually try to anticipate all the synonyms you
		are likely to come up with, but they may not have thought of yours.^^";
	print (ESB) "Try variations.  ",
		"Sometimes an action doesn't work, but *does* produce some
		kind of unusual result. These are often indications that you're on the
		right track, even if you haven't figured out quite the right approach
		yet. Pressing the red button alone may only cause a grinding noise from
		inside the wall, so perhaps pressing the blue and *then* the red will open
		the secret door.^^";
	if (ES_Pause()) jump end;
	print (ESB) "Try to understand the game's internal logic.  ",
		"Sometimes there is a system
		in play that does not operate in the normal world -- a kind of magic, for
		instance, or technology we don't have on modern-day earth. If you've been
		introduced to such a system in the game, ask yourself how you might apply
		it to the situations that are still causing you problems.^^";
	print (ESB) "Check the *whole* screen.  ",
		"Are there extra windows besides the main
		window?  What's going on in those?  Check out the status bar, if there is
		one -- it may contain the name of the room you're in, your score, the time
		of day, your character's state of health, or some other important
		information. If there's something up there, it's worth paying attention
		to that, too. When and where does it change? Why is it significant? If
		the bar is describing your character's health, you can bet there is
		probably a point at which that will be important.^^";
	if (ES_Pause()) jump end;
	print (ESB) "Consider the genre of the game.  ",
		"Mysteries, romances, and thrillers all
		have their own types of action and motivation. What are you trying to do,
		and how do conventional characters go about doing that? What's the right
		sort of behavior for a detective/romance heroine/spy?^^";
	print (ESB) "Play with someone else.  ", "Two heads are usually better than one.^^";
	print (ESB) "Try typing HINT, HELP, INFO, ABOUT:  ", "one or more of these are often
		implemented as a source of suggestions about how to get past difficult
		spots. If that doesn't work, try emailing the author or (better yet)
		posting a request for hints on the newsgroup rec.games.int-fiction. For
		best results, put the name of the game you want help with in the subject
		line; then leave a page or so of blank ~spoiler space~ (so that no one
		will read about where you got to in the game unless they've already played
		it), and describe your problem as clearly as possible. Someone will
		probably be able to tell you how to get around it.^^";
	if (ES_Pause()) jump end;
	print (ESB) "Email the author:  ",
		"If you're stuck somewhere that just makes no sense at all, it's possible
		that you're facing a bug. If you think you are, you should email the
		author (politely) to report the problem and ask for a way around it.^^";
	.end;
	"Good luck!";
];


!---------------------------------------------------------------------------
! Standard Verbs list
!---------------------------------------------------------------------------

[ StandardVerbs flag;
	print "Here is a list of the standard instructions in games like this.
		You should be aware that the game you are playing may introduce some other
		verbs, as well. This list is just a place to start:^^";
	style fixed;
	print "LOOK          ";
	print "EXAMINE       ";
	print "SEARCH        ";
	print "LOOK UNDER    ";
	print "^";
	print "^";

	print "INVENTORY     ";
	print "TAKE          ";
	print "DROP          ";
	print "EMPTY         ";
	print "^";

	print "REMOVE        ";
	print "PUT ON        ";
	print "PUT IN        ";
	print "TRANSFER      ";
	print "^";
	print "^";

	print "NORTH    [N]  ";
	print "SOUTH    [S]  ";
	print "EAST     [E]  ";
	print "WEST	    [W]  ";
	print "^";

	print "[NE]          ";
	print "[NW]          ";
	print "[SE]          ";
	print "[SW]          ";
	print "^";

	print "UP            ";
	print "DOWN          ";
	print "IN            ";
	print "OUT           ";
	print "^";
	if (ES_Pause()) jump end;

	print "GO            ";
	print "ENTER         ";
	print "EXIT          ";
	print "GET OFF       ";
	print "^^";

	print "CLIMB         ";
	print "SWIM          ";
	print "JUMP          ";
	print "JUMP OVER     ";
	print "^^";

	print "LOCK          ";
	print "UNLOCK        ";
	print "OPEN          ";
	print "CLOSE         ";
	print "^";

	print "SWITCH ON     ";
	print "SWITCH OFF    ";
	print "SET           ";
	print "TURN          ";
	print "^";

	print "PULL          ";
	print "PUSH          ";
	print "PUSH NORTH    ";
	print "THROW AT      ";
	print "^";

	print "SWING         ";
	print "WAVE          ";
	print "RUB           ";
	print "SQUEEZE       ";
	print "^";

	print "EAT           ";
	print "DRINK         ";
	print "WEAR          ";
	print "TAKE OFF      ";
	print "^";

	print "LISTEN        ";
	print "TASTE         ";
	print "TOUCH         ";
	print "SMELL         ";
	print "^";

	print "BURN          ";
	print "DIG           ";
	print "CUT           ";
	print "TIE           ";
	print "^";

	print "BLOW          ";
	print "BREAK         ";
	print "FILL          ";
	print "CONSULT       ";
	print "^";

	print "WAIT          ";
	print "SLEEP         ";
	print "SING          ";
	print "THINK         ";
	print "^^";

	print "GIVE          ";
	print "SHOW          ";
	print "WAKE          ";
	print "KISS          ";
	print "^";

	print "ATTACK        ";
	print "BUY           ";
	print "^";
	if (ES_Pause()) jump end;
	print "^^";

	style roman;
	print "Added Verbs:";
	print "^^";

	style fixed;
	print "FORE [F]      ";
	print "AFT [A]       ";
	print "STARBOAD [SB] ";
	print "PORT [P]      ";
	print "^";

	print "CRAWL         ";
	print "HIDE          ";
	print "FIX           ";
	print "KICK          ";
	print "^";

	print "PLUG          ";
	print "STEP          ";
	print "STRAP         ";
	print "TALK          ";
	print "^";

	print "TRIP          ";
	print "UNPLUG        ";
	print "UNSTRAP       ";
	print "USE           ";
	print "^^";

	print "ANSWER        ";
	print "ASK           ";
	print "ASK <C> TO    ";
	print "TALK TO <C>   ";
	print "^";

	print "TELL          ";
	print "TELL <C> TO   ";
	print "^";
	if (ES_Pause()) jump end;

	style roman;
	print "^The following commands control the game itself:^^";

	style fixed;
	print "RESTART    RESTORE    SAVE^";
	print "QUIT       UNDO       PRONOUNS^";
	print "SCRIPT ON  SCRIPT OFF VERIFY^";
#ifndef NO_PLACES;
	print "OBJECTS    PLACES     ^";
#endif;
#ifdef MAX_SCORE;
	if (max_score > 0)
	{	print "SCORE      ";
		print "NOTIFY ON  ";
		print "NOTIFY OFF ";
		flag = 1;
	}
#endif;
#ifdef TASKS_PROVIDED;
	if (max_score > 0)
	{
		print "FULL SCORE";
		flag = 1;
	}
#endif;

	.end;
	style roman;
	"";
];

[ Abbreviations;
	print "Standard abbreviations are as follow:^^";
	style fixed;
	print "A -- AFT.  Only on the ship, and the space station.^";
	print "D -- DOWN.^";
	print "E -- EAST.^";
	print "F -- FORE.  Only on the ship, and the space station.^";
	print "G -- AGAIN.  Repeat the previous command.^";
	print "I -- INVENTORY.  See what you're holding.^";
	print "L -- LOOK.  See what's around you.^";
	print "N -- NORTH.^";
	if (ES_Pause()) jump end;
	print "NE -- NORTHEAST.^";
	print "NW -- NORTHWEST.^";
	print "P -- PORT.  Only on the ship, and the space station.^";
	print "Q -- QUIT.^";
	print "S -- SOUTH.^";
	print "SB -- STARBOARD.  Only on the ship, and the space station.^";
	print "SE -- SOUTHEAST.^";
	print "SW -- SOUTHWEST.^";
	print "U -- UP.^";
	print "W -- WEST.^";
	print "X -- EXAMINE (something).^";
	print "Z -- WAIT.^";
	.end;
	style roman;
	"";
];

!---------------------------------------------------------------------------
! About the IF community online
!---------------------------------------------------------------------------

[ OnlineHelp;
	print (ESB) "IF HELP ONLINE^^";
		print "Some online sources of introductory help for IF games include:^^";
		print "Frederik Ramsberg's Beginner's Guide, http://www.microheaven.com/IFGuide/^";
		print "Interactive Fiction -- Getting Started, http://adamcadre.ac/content/if.txt^";
		print "Emily Short's site, http://www.mindspring.com/@@126emshort/Site/How%20to%20Play.html^";
		print "For more information about IF, the IF community, and other games to play,
			you should also try:^^";
		if (ES_Pause()) jump end;
		print "Brasslantern, http://www.brasslantern.org/^";
		print "Baf's Guide to Interactive Fiction, http://www.wurb.com/if/index^^";
		print "You may also ask for specific information and game hints on the newsgroup
			rec.games.int-fiction.^^";
		print "If you are not familiar with newsgroups and don't have
			a newsreader already set up, you may access it by going to http://groups.google.com/
			and selecting ~rec~, then ~rec.games~, then ~rec.games.int-fiction.~ You will
			be presented with a long list of things that people are already talking about.
			If you've never read this newsgroup before, you should look for a thread with the
			word ~FAQ~ in the title, and read it: this will give you instructions about how
			to post without breaking any of the community's rules of etiquette. (They're
			not especially fussy, but following them will get you prompter and more polite
			assistance.)^^";
		print "Once you've done that, you may post
			a new message with a clearly labelled subject (like ~[HINT REQUEST] Jigsaw~ or
			~Looking for Mystery Games~). Afterwards, wait a few hours and check the newsgroup again
			to see whether anyone has an answer for you.^";
		if (ES_Pause()) jump end;
		.end;
		print "^^^";
];


[ MoreGames;
	print (ESB) "MORE SOURCES OF IF^^";
	print "There are more games like this at the IF Archive, www.ifarchive.org.^^";
	print "Instructions on setting them up are available from Frederik Ramsberg's
		Beginner's Guide, http://www.microheaven.com/IFGuide/^";
	print "Guides to good IF (for beginners or in general) are to be found at the Beginner's
		Guide just mentioned, or at Baf's Guide to Interactive Fiction, http://www.wurb.com/if/index.";
];
