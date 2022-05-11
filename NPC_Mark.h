! Character drops "g"s off of ing  so missin'  instead of missing      '

! *********************************************************************************
! The attendant will watch T.V. in the past and play with his phone in current time
! *********************************************************************************
! Age: 20

!        [Grunk can try TELL GNOME ABOUT GRUNK or ASK GNOME ABOUT
!        GNOME or ASK GNOME ABOUT THIS PLACE. And probably lots of
!        other thing too.]

!        [You can try TELL GNOME ABOUT GRUNK or ASK GNOME ABOUT
!        GNOME or ASK GNOME ABOUT THIS PLACE. There''s also lots of
!        other thing too.]

! Character Diamond
! 1: Lazy - Mellow
! 2: Cocky, Knows It All
! 3: Depressed - Doesn't Want To Work At Station
! 4: Honest

! ---------------------------------------------------------------------------- !
!       MARK. 08/10/16
!

  Object  -> gasStationMark "attendant"
    with  name 'mark' 'attendant' 'man' 'guy' 'dude' 'teen' 'shaggy' 'clerk',
          describe [;
              rtrue;
          ],
          daemon [;
              ! Used if the player asks about "WORK"
              if (self.askedWork) {
                  iCharacterTalkDelay++;
              }
              if (iCharacterTalkDelay > 1) {
                  iCharacterTalkDelay = 0;
                  self.askedWork = false;
              }

              ! Used if the player tells about "Eviction"
              if (self.tellAboutEviction) {
                  iTellMarkEvict++;
              }
              if (iTellMarkEvict > 1) {
                  iTellMarkEvict = 0;
                  self.tellAboutEviction = false;
              }

              ! Used in response to the question if the PC is going to talk all night

              if (self.talkAllNight) {
                  iTalkAllNight++;
              }
              if (iTalkAllNight > 1) {
                  iTalkAllNight = 0;
                  self.talkAllNight = false;
              }

              ! Used in response to Mark telling the PC to move on

              if (self.buySomething) {
                  iBuySomething++;
              }
              if (self.dontKillBuySomething) {
                  self.dontKillBuySomething = false;
              } else {
                  if (iBuySomething > 1) {
                      iBuySomething = 0;
                      self.buySomething = false;
                  }
              }
          ],
          before [ w1;
              AskCreatureFor:
                  wn = consult_from;
                  w1 = NextWord();
                  switch (w1) {
                      'cigarette', 'cigarettes', 'cig', 'cigs', 'fag', 'fags', 'smokes':
                          return AskMarkCig();
                      'key':
                          return AskMarkKey();
                      'name':
                          return AskForNameMark();
                      'phone', 'iphone':
                          "~Who do you think you are? This thing is my lifeblood. Don't even look at it.~";
                      'change', 'quarters', 'quarter':
                          "~You're broke. You're always broke. So I don't have to make change for you.~";
                  }
                  return MarkResponse();
              Examine:
                  if (gasStationMark.angryAttendant)
                      "The attendant is angry. ~I'd get out of here if I were you,~ he says.";
                  if (gasStationBooth.attendantCall)
                      "The attendant is on the phone.";
                  print "The shaggy attendant doesn't seem to notice you as he ";
                  if (self.eyesOpen) {
                      self.eyesOpen = false;
                      "turns back to his phone.";
                  }
                  "plays with his phone.";
              Talk:
                  print "[You can try ";
                  if (self.askedSam) {
                      print "ASK ABOUT SCIENTIST";
                  } else {
                      print "ASK ABOUT SAM";
                  }
                  print " or ";
                  if (self.askedCigs) {
                      print "ASK ABOUT TRAILER PARK";
                  } else {
                      print "ASK ABOUT CIGARETTES";
                  }
                  print " or ";
                  if (self.askedAlley) {
                      print "ASK ABOUT WORK";
                  } else {
                      print "ASK ABOUT BOWLING ALLEY";
                  }
                  ". There are also lots of other things too.]";
              Hello:
                  if (self.eyesOpen) {
                      self.eyesOpen = false;
                      "~What's up?~ the attendant asks, lowering his eyes back to his phone.";
                  }
                  "~What's up?~ the attendant asks, not lifting his eyes up from his phone.";
              WaveObject:
                  if (self.eyesOpen) {
                      self.eyesOpen = false;
                      "~Yeah. Yeah. I see you,~ the attendant says turning back to his phone, ~what do you want?~";
                  }
                  "~Yeah. Yeah. I see you,~ the attendant says not even looking up from his phone, ~what do you want?~";
              Pet:
                  "While he wouldn't appreciate that, he's also sitting in the booth.";
              Eat, Taste:
                  "What? Are you a cannibal? I know you're not that hungry.";
              Take:
                  "You know he's not an object?";
              Attack, Blow, Burn, Buy, Climb, Close, Cut, Dig, Drink, Eat, Empty, Enter, Exit, GetOff, Go, JumpOver, Kick, Kiss, Listen, LookUnder, Open:
                  "You can't do that. He's behind Plexiglas.";
              Push, PushDir, Pull, Read, Remove, Rub, Search, Set, SetTo, SmellNoun, Squeeze, Swing, SwitchOn, SwitchOff, Take, Talk, Taste, Tie, Touch, Transfer, Turn, Unlock, Wave:
                  "You can't do that. He's behind Plexiglas.";
          ],
          life [ w1;
              if (testAngryAttendant()) rtrue;
              Answer:
                  switch(noun) {
                      t_hi: <<Hello self>>;
                      t_yes: return AnswerYesMark();
                      t_no: return AnswerNoMark();
                      t_sorry: if(testSorry()) rtrue;
                      t_goodbye: "~I'm sure I'll be seein' you again tonight.~";
                      t_thanks: "~I don't know why you're thanking me.~";
                      default:
                          return MarkResponse();
                  }
              Ask:
                  wn = consult_from;
                  w1 = NextWord();
                  switch (w1) {
                      'halloween', 'samhain':
                          "~I love it. Ghosts and ghouls don't scare me and the weather's great.~";
                      'candy':
                          "~I eat it whenever I get the chance, but I don't think I have a sweet tooth.~";
                      'mothership':
                          "~What? Are you with Tom on this or something? There are no lights in the sky and no mothership is going to touch down.~";
                      'lights':
                          if (mapleRoad.firstTime) "~No biggy. I can see enough to text my girlfriend.~";
                          "~What? Are you with Tom on this or something? There are no lights in the sky and no mothership is going to touch down.~";
                      'ufo', 'ufos', 'chemtrails', 'roswell', 'hanager':
                          "~Don't ask me about that. Tom's the one into all those conspiracy theories.~";
                      'booth':
                          "~It's a little cramped in here, but who cares. I got my phone.~";
                      'covid', 'bug', 'corona', 'coronavirus', 'virus':
                          "~They say it's hitting the country hard, but we're isolated from it. That's why I think Jerry just came down with a fall bug.~";
                      'bowling', 'alley':
                          if(self.askedAlley) "~Not my type of place. I'd rather just get a six-pack and chill at home.~";
                          self.askedAlley = true;
                          "~What? You're goin' over to the alley?~
                          ^^You tell him that you're looking for Sam and he might be down there.
                          ^^~Sam and you will never learn. I bet he's down there right now gettin' plowed off those taps.
                          Have fun with that.~";
                      'house', 'abandoned':
                          "~The one behind the alley? It's amazin' it's still standing. You'd think someone
                          would bulldoze it into the ground.~";
                      'bathroom', 'lavatory', 'washroom', 'head':
                          if (self.askedBathroom) "~I already told you. Payin' customers only. Go over to the alley if you have to use it.~";
                          self.askedBathroom = true;
                          if (self.askAboutKey) print "~Look, I already told you";
                          else print "~Really, you know the rules";
                          ", customers only. If you ain't buyin', you're not usin' it.~
                          ^^You ask him to give you a break and let you use it this one time.
                          ^^~If I did that for you, I'd have to do it for everybody. I'd get nagged to death.
                          Hell no. Get out of here. Go use the one over at the alley.~";
                      'cigarette', 'cigarettes', 'cig', 'cigs', 'fag', 'fags', 'smokes':
                          return AskMarkCig();
                      'city', 'town', 'sunnybrook', 'people':
                          "~The town's been goin' through some hard times. Ever since Melville closed its
                          factories, people have been leavin' Sunnybrook.~";
                      'current', 'date', 'year':
                          "~What about it? 2020. The election's soon. I know who I'm gonna vote for.~";
                      'key':
                          return AskMarkKey();
                      'name':
                          return AskForNameMark();
                      'note', 'notes':
                          if (self.seenScientist) "~I don't want them. But if you catch that guy, maybe you can return the papers.~";
                          "~What are you even talkin' about?~";
                      'trailer', 'park':
                          self.eyesOpen = true;
                          "~Most of them are good people. Except the ones that bother me for cigarettes
                          all the time,~ he says eyeing you.";
                      'phone', 'iphone':
                          "~Yeah. Sorry. Textin' my girlfriend. You know how it is. You can't
                          get them off these things.~";
                      'convenience', 'drug', 'store':
                          "~Sometimes, I get beer from there even though I'm not old enough to buy. They're
                          pretty cool when it comes to that.~";
                      'pharmacy':
                          "~What pharmacy? The convenience store has beer in the back.~";
                      'mark', 'himself', 'him', 'attendant', 'man', 'dude', 'teen':
                          if (self.askedAboutMark) "~As I said. I want to get out of here.~";
                          self.askedAboutMark = true;
                          "~You've never asked me that. Hm. Well. I want to make it out of this town someday.
                          Don't we all? Who knows. Not even sure where I'd go.~";
                      'sam':
                          if (self.askedSam) "~Come on. I've already told you. I don't know.~";
                          self.askedSam = true;
                          "~I can't say that I've seen him. It's been busy 'round here.~^
                          ^You push him to see if he can remember anything.^
                          ^~Look. Sam might have come this way. I don't know. To be honest,
                          I don't pay a lot of attention to the people 'round here.~";
                      'school', 'schooling':
                          "~Hated goin' to school in this town. It's so dull.
                          Was glad when I started workin' here. But to tell you the truth, it's not
                          much better.~";
                      'college':
                          "~I thought about college once, but you have to do good in school. School sucked.~";
                      'art', 'gallery':
                          "~What? Over on South & Ryders? That's not a gallery. That's the 'Crazy Monkey.'~";
                      'crazy', 'monkey', 'tattoo', 'tatoo', 'tattoos', 'tatoos', 'tattoing':
                          "~The tattoo shop? They do some great work. Nick runs the place, but I don't know.
                          They cost a lot anyways.~";
                      'post', 'office':
                          "~I thought about working over at the post office, but doin' what? This isn't much better, but at least I can play with my phone.~";
                      'yard', 'junkyard', 'millers', 'miller', 'miller^s', 'miller?s':
                          "~The old junkyard? It's closed down. There are cars still back there, but Miller
                          quit runnin' the place years ago.~";
                      'dog', 'doberman':
                          "~There's no dog over at Miller's yard. What are you talkin' about?~";
                      'scientist', 'guy':
                          if (self.seenScientist) "~That guy,~ the attendant says, nodding towards the north, ~he's not a regular here.~";
                          "~Not sure who you're talkin' about,~ the attendant shrugs.";
                      'yukypah', 'heef', 'statue':
                          "~I don't know why they still teach about him. I think it just pisses the
                          kids off and that's the reason there's so much graffiti all over it.~";
                      'bus':
                          "~That bus goes all the way out to Springfield now that Melville closed down.~";
                      'springfield':
                          "~The town still has a bit of manufacturin', but I think it's just as shaky as Melville was.~";
                      'melville', 'melvill':
                          "~What about Melville. When the factories closed down, so did the city.
                          No one lives there anymore.~";
                      'change', 'quarters', 'quarter':
                          "~You're broke. You're always broke. So I don't have to make change for you.~";
                      'graffiti':
                          "~The town's covered in it. A bunch of kids that think they're a gang
                          runs around here. They're punks. None of them have any respect.~";
                      'library':
                          "~That place is a wreck. No one cares about readin' in this town.~";
                      'the', 'tavern', 'bar':
                          "~That place closed a few months ago. The owner couldn't keep it open.
                          You know how it is, times have been tough around here. Too many people have moved away.~";
                      'station', 'work', 'job', 'shop', 'place':
                          if (self.askedStation) "~I don't want to talk. You know how I feel about it.~";
                          self.askedStation = true;
                          self.askedWork = true;
                          print "~Workin' here's cool enough. Maybe the easy way, you know,~ he says ";
                          if (self.eyesOpen == false) {
                              self.eyesOpen = true;
                              print "looking up for a second";
                          } else {
                              print "with a shrug";
                          }
                          ". ~But I've always felt I should be doin' more. Ah. Probably think about it too much.~
                          ^^You tell him that you're sure he's doing the best he can.
                          ^^~But that's just it. Am I?~";
                      'garage':
                          "~It's not that big, and there are two cars from the '50s crammed in there. Plus, it's full of other junk. So much, it's hard to move around. Jerry said he'd clean it out but still hasn't.~";
                      'judy':
                          print "~Judy? You know her better than me with all the time you spend over there. ";
                          if (self.askedAlley) "I guess you're headed down there now. Have fun.~";
                          "Looks like you're headed down there right now.~";
                      'amy', 'clerk':
                          "~What? The old lady that works over at the convenience store? God. I hope I don't end up like her.~";
                      'tom':
                          "~Tom's a little nutty. You know? Always goin' on about UFOs. I hope one day they take
                          him away. But he probably hopes that too.~";
                      'bum', 'ed', 'eddie':
                          "~A bum, you say. No one like that lives around here, and the kids that wander the streets would keep it that way.~";
                      'doorman':
                          "~There's always one workin' over at Highland Towers. Stay away from there.
                          He'll only bust your balls.~";
                      'complex', 'high-rise', 'highrise', 'highland', 'towers', 'apartment', 'apartments':
                          "~That place is run down. Highland Towers use to be for the rich. Not anymore.~";
                      'jerry':
                          if (self.askAboutJerry)
                              "~He's my boss and hired me. When he works nights, it's all about getting the paperwork done for the station.~";
                          self.askAboutJerry = true;
                          "~Jerry is probably goin' to be out for a few days. Came down with a nasty bug. I hope it's not COVID.~";
                      'harry':
                          "~Harry. Harry? I don't recall anyone like that. Must be so close to Jerry's name.~";
                      'phil', 'phill':
                          "~Phil? No. I can't say that I've ever heard of him.~";
                      'mabel':
                          "~I don't know a Mabel. Are you just tryin' to trick me?~";
                      'nancy', 'punk':
                          "~You know when I was younger I think I heard of a Nancy that left this city.
                          She ended up missin' somewhere. New York? New Orleans? I can't remember.
                          Probably just an urban legend.~";
                      'nick', 'biker':
                          "~The old biker guy that runs the tattoo shop? I don't know. That's not my
                          thing. I don't want them drawin' blood and stickin' ink.~";
                      'sarah':
                          "~Sarah? There's no one by that name in this town. Who are you talkin' about?~";
                      'madame', 'sorra', 'gypsy', 'fortune-teller', 'fortune', 'teller':
                          "~You mean that old fortune-teller. What about her? She's creepy. Gotta be over a hundred years old.
                          Like a decrepit vampire or somethin'. Kids believe she's a witch.~";
                      'plug', 'spark', 'sparkplug', 'fuse':
                          "~What are you goin' to do with a spark plug? Go on. Get out of here.~";
                      'sign', 'gas', 'gasoline':
                          if (self.askAboutSign) "~Yeah. Price shot up. People complain, but they have to fill their tanks.~";
                          self.askAboutSign = true;
                          "~The price was low six months ago, but it's shot up since then.~";
                      'price', 'war':
                          "~Yeah. There was some kind of price war. I don't follow that stuff closely.~";
                      'girlfriend':
                          "~Yeah, we got into a fight when I forgot our one month anniversary. One month! I think she's crazy. But hot.~";
                      'texting':
                          "~I hate typing on this thing. But my girlfriend is pissed at me. She keeps going on and on. I don't think it'll ever end.~";
                      'pump', 'pumps':
                          "~Why are you bothering me about them? You don't even own a car.~";
                      'me', 'self', 'yourself':
                          "~Why are you asking weird questions like that? I don't pry into your life. Go on, get out of here.~";
                      'him', 'himself', 'her', 'herself', 'them':
                          "At the moment, even the simplest questions are confusing.";
                      default:
                          return MarkResponse();
                  }
              Tell:
                  if (testAngryAttendant()) rtrue;
                  wn = consult_from;
                  w1 = NextWord();
                  switch(w1) {
                      'hi', 'hello', 'hola', 'greetings':
                          <<Hello self>>;
                      'yes', 'please', 'ok':
                          return AnswerYesMark();
                      'no':
                          return AnswerNoMark();
                      'good':
                          "~Sounds like you're doing better than me.~";
                      'bad':
                          "~Times are iffy now for sure.~";
                      'sorry':
                          if(testSorry()) rtrue;
                      'goodbye', 'goodby', 'good-bye', 'bye', 'cheerio':
                          "~I'm sure I'll be seein' you again tonight.~";
                      'scientist':
                          if (self.seenScientist) "~I saw him pass through here, but he didn't buy anything, so who cares?~";
                          "~Who you talkin' about?~";
                      'him', 'himself', 'her', 'herself', 'them':
                          "At the moment, even the simplest statements are confusing.";
                      'thanks', 'thank': "~I don't know why you're thanking me.~";
                      'mothership':
                          "~Yeah. Right. You think I believe that? You and Tom were made for each other. Go find him.~";
                      'covid', 'bug', 'corona', 'coronavirus', 'virus': "~Yeah. Yeah. I know about it. I'm isolated in this booth anyways.~";
                      'evict', 'eviction', 'sam', 'trailer', 'me', 'self', 'yourself':
                          if (self.toldEvict) "You've already told him about that.";
                          self.toldEvict = true;
                          self.tellAboutEviction = true;
                          "You tell him the manager over at the trailer park found out Sam was living there.^
                          ^~What? That greazy old man is going to throw you out? You should probably move on anyways. Haven't you lived up there long enough?~";
                      'tom':
                          if (mapleRoad.firstTime) "~What about him? That guy gets under my skin.~";
                          "You tell him Toms freaking out down the street.^
                          ^~That guy's outta his gourd. I don't know if you can calm him down or not. He gets under my skin.~";
                      default:
                          "~I don't know if I can help with that.~";
                  }
          ],
          orders [;
              if (testAngryAttendant()) rtrue;
              Buy:
                  if (noun == gasStationPumps) "~What are you talkin' about? You don't have a car. I'm not sellin' you any gas.~";
                  if (noun == gasStationCigarettes) "~You're always busted. I ain't givin' you nothin'.~";
              Hello:
                  <<Hello self>>;
              Give:
                  if (noun == gasStationPumps) "~What are you talkin' about? You don't have a car. I'm not sellin' you any gas.~";
                  if (noun == gasStationCigarettes) "~You're always busted. I ain't givin' you nothin'.~";
                  "~Oh yeah. I'd love to hand that out,~ he says sarcastically. ~What were we talkin' about again?~";
              Open:
                  if (noun == gasStationBooth)
                      "~I'm not lettin' you in here.~";
                  "~Oh yeah. I'd love to open that,~ he says sarcastically. ~What were we talkin' about again?~";
              Strong: "The attendant ignores you.";
          ],
          eyesOpen false,
          askedSam false,
          askedCigs false,
          askedWork false,
          askedAlley false,
          askedStation false,
          askedBathroom false,
          askAboutKey false,
          askAboutJerry false,
          talkAllNight false,
          buySomething false,
          dontKillBuySomething false,
          nameFirtTime true,
          angryAttendant false,
          askedAboutMark false,
          seenScientist false,
          toldEvict false,
          tellAboutEviction false,
          askAboutSign false,
    has   animate male concealed;

  [ testAngryAttendant;
        if (gasStationMark.angryAttendant)
            "~If I were you I'd just get out of here. County is goin' to be pissed when they show up.~";
        if (gasStationBooth.attendantCall)
            "The attendant is on the phone and not paying attention.";
        rfalse;
  ];

  [ testSorry;
        if (gasStationBooth.boothAttacked) "~Look. Why don't you just move on. I got better things to do tonight.~";
        "~If you're not goin' to buy somethin'. Move on.~";
  ];

  [ MarkResponse;
        iMarkReaction--;
        switch(iMarkReaction) {
            1: gasStationMark.talkAllNight = true;
               "~What are you goin' to do? Go on all night?~";

        }
        if (iMarkReaction < 0) iMarkReaction = 0;
        if (gasStationMark.buySomething) gasStationMark.dontKillBuySomething = true;
        gasStationMark.buySomething = true;
        "~If you're not goin' to buy somethin'. Move on!~";
  ];

  [ AskForNameMark;
        SelfPlayer.knowMark = true;
        if (gasStationMark.nameFirtTime) {
            gasStationMark.nameFirtTime = false;
            iPeople++;
            "~What? Are you losin' it? Mark's my name. You know that.~";
        }
        "~I think you really are loosin' it.~";
  ];

  [ AnswerYesMark;
        if (gasStationMark.buySomething) "~Have a good night.~";
        if (gasStationMark.talkAllNight) "~Then take it somewhere else.~";
        if (gasStationMark.askedWork) "~Thanks for the encouragement. I just don't know.~";
        if (gasStationMark.tellAboutEviction) "~Nice. Glad you agree. I'd get out if I could.~";
        "~Did I ask you a question?~";
  ];

  [ AnswerNoMark;
        if (gasStationMark.buySomething) "~Come on. Quit messin' with me.~";
        if (gasStationMark.talkAllNight) "~Then get out of here.~";
        if (gasStationMark.askedWork) "~Yeah. That's what I'm afraid of.~";
        if (gasStationMark.tellAboutEviction) "~If you say so, but there's no reason to stick around.~";
        "~Did I ask you a question?~";
  ];

  [ AskMarkCig;
        if (gasStationMark.askedCigs)
            "~As I said. I ain't givin' nothin' away for free. When you have some cash, come back.~";
        gasStationMark.askedCigs = true;
        "~Look. You're always busted. I ain't givin' you nothin'.~
        ^^You tell him you'll pay him tomorrow, that you're good for it.
        ^^~If I had a dollar every time someone said that, I wouldn't have to work here anymore.~";
  ];

  [ AskMarkKey;
        if (gasStationMark.askAboutKey) "~I already told you. Payin' customers only. Go over to the alley if you have to use it.~";
        gasStationMark.askAboutKey = true;
        if (gasStationMark.askedBathroom) print "~I already told you";
        else print "~Look";
        gasStationMark.askedBathroom = true;
        ", the bathroom is only for payin' customers,~ the attendant tries to explain, ~you know,
        people who have been on the road for a long time and need to use it.~";
  ];
