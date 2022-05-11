
! Character Diamond
! 1: Mediocre - Not Ambitious - Lazy In School
! 2: Nice - Honest
! 3: Unhappy - Life Ground Her Down
! 4: Introvert - Afraid

! ---------------------------------------------------------------------------- !
!       OLD AMY. 06/24/19
! Age: 57

  Object  -> convenienceStoreOldAmy "clerk"
    with  name 'amy' 'attendant' 'old' 'lady' 'woman' 'clerk' 'older',
          describe [;
              rtrue;
          ],
          daemon [;
              ! Returns Amy back to her paperback
              if (self.lookUp) {
                  iAmyLookUp++;
              }
              if (self.dontKillLookUp) {
                  self.dontKillLookUp = false;
              } else {
                  if (iAmyLookUp >= 2) {
                      self.lookUp = false;
                      iAmyLookUp = 0;
                      "^The clerk turns back to her book, trying to forget you.";
                  }
              }

              ! Used when Amy is embarrassed about a kiss that took place in the house with Jerry
              if (self.knowAboutKiss) {
                  iAskKiss++;
              }
              if (self.dontKillknowAboutKiss) {
                  self.dontKillknowAboutKiss = false;
              } else {
                  if (iAskKiss > 1) {
                      iAskKiss = 0;
                      self.knowAboutKiss = false;
                  }
              }

              ! Used when Amy ask if the player heard of On The Road
              if (self.askAboutBook) {
                  iAskBook++;
              }
              if (self.dontKillaskAboutBook) {
                  self.dontKillaskAboutBook = false;
              } else {
                  if (iAskBook > 1) {
                      iAskBook = 0;
                      self.askAboutBook = false;
                  }
              }

              if (self.askAboutSelfDaemon) {
                  iOldAmyAskSelf++;
              }
              if (iOldAmyAskSelf > 1) {
                  iOldAmyAskSelf = 0;
                  self.askAboutSelfDaemon = false;
              }

          ],
          before [ w1;
              AskCreatureFor:
                  iAmyConversation++;
                  wn = consult_from;
                  w1 = NextWord();
                  switch (w1) {
                      'name':
                          return AskForNameOldAmy();
                      'beer', 'alcohol', 'booze':
                          TestLookingUp();
                          "~Sorry. There's no beer. A bunch of college kids came in and bought us out. You know how it is.~";
                      'cigarette', 'cigarettes', 'cig', 'cigs', 'fag', 'fags', 'smokes':
                          TestLookingUp();
                          "~You know how it is. Everybody's trying to go healthy. We recently stopped selling cigarettes.~";
                      'change', 'quarters', 'quarter':
                          TestLookingUp();
                          "~Sorry. I'm not going to open up this register. You need to buy something.~";
                      'soda', 'pop', 'coke', 'cokes', 'cola':
                          TestLookingUp();
                          <<Buy convenienceStoreAds>>;
                  }
                  return OldAmyResponse();
              Examine:
                  if (self.lookUp) {
                      self.lookUp = false;
                      iAmyLookUp = 0;
                      print "Looking back down with tired eyes, Amy turns a page";
                  } else {
                      print "Starting to gray, Amy sits behind the counter engrossed in a paperback";
                  }
                  ". She's worked this store for as long as you lived here, and has always kept
                  things close to the vest.";
              Kiss:
                  self.lookUp = true;
                  "~I'm a little old for that, okay,~ she says, pushing you back.";
              Talk:
                  if (convenienceStoreOldAmy.lookUp) convenienceStoreOldAmy.dontKillLookUp = true;
                  print "[You can try ";
                  if (self.askAboutSamTalk) {
                      print "ASK ABOUT TOWN";
                  } else {
                      print "ASK ABOUT SAM";
                  }
                  print " or ";
                  if (self.askAboutStoreTalk) {
                      print "ASK ABOUT READING";
                  } else {
                      print "ASK ABOUT STORE";
                  }
                  ". There are also lots of other things too.]";
              Hello:
                  iAmyConversation++;
                  TestLookingUp();
                   "~How are you tonight?~";
              Eat, Taste:
                  "What? Are you a cannibal? I know you're not that hungry.";
              WaveObject:
                  if (self.lookUp) {
                      self.dontKillLookUp = true;
                      "~Yes, what do you need?~";
                  }
                  self.lookUp = true;
                  print (string) random("~Hm,~ the clerk says, raising her head to look up at you.^",
                  "~What,~ the clerk asks, raising her head to look up at you.^",
                  "~Yeah,~ the clerk says, raising her head to look up at you.^");
                  rtrue;
              Take:
                  "You know she's not an object?";
              Attack, Blow, Burn, Climb, Close, Cut, Dig, Drink, Eat, Empty, Exit, GetOff, JumpOver, Kick, Listen, LookUnder, Open:
                  "You can't do that. She's behind the counter.";
              Push, PushDir, Pull, Read, Remove, Rub, Search, Set, SetTo, SmellNoun, Squeeze, Swing, SwitchOn, SwitchOff, Take, Talk, Taste, Tie, Touch, Transfer, Turn, Unlock, Wave:
                  "You can't do that. She's behind the counter.";
          ],
          life [ w1 w2;
              Answer:
                  if (self.lookUp) self.dontKillLookUp = true;
                  self.lookUp = true;
                  iAmyConversation++;
                  switch(noun) {
                      t_hi: <<Hello self>>;
                      t_yes:
                          if (self.askAboutSelfDaemon) "~I doubt that.~";
                          if (self.askAboutBook) "~Then you can appreciate what he did. Not may can.~";
                          "~I'm glad you're happy. At least someone is.~";
                      t_no:
                          if (self.askAboutSelfDaemon) "~At least you're honest.~";
                          if (self.askAboutBook) "~You're like everybody else in this town. But it's what I've come to expect.~";
                          "~Try not to be down. Life should be a joy. Or at least you'd think.~";
                      t_good: "~I'm happy for you.~";
                      t_bad: "~That'll happen.~";
                      t_sorry: "~Yeah... Hm. Okay, sure.~";
                      t_thanks: "~Yeah. Sure.~";
                      t_goodbye:
                          if (self.lookUp) {
                              self.lookUp = false;
                              iAmyLookUp = 0;
                              "~Yeah. Bye,~ she says, turning back to her book.";
                          } else {
                              "~Yeah. Bye,~ she says, not even looking up.";
                      }
                      default:
                          return (OldAmyResponse());
                  }
              Ask:
                  iAmyConversation++;
                  wn = consult_from;
                  w1 = NextWord();
                  w2 = NextWord();
                  if (w1 == 'star' ) {
                      if (w2 == 'wars' ) {
                          TestLookingUp();
                          "~Star Wars was all anybody would talk about when I was a kid. Haven't seen it in a long time.~";
                      }
                  }
                  if (w1 == 'college' ) {
                      if (w2 == 'kids' ) {
                          TestLookingUp();
                          "~They stopped by. Hm. We have cheap beer on sale.~";
                      }
                  }
                  switch(w1) {
                      'halloween', 'samhain':
                          TestLookingUp();
                          "~Can't wait. It's fun seeing the kids. Some of them stop by.~";
                      'bowling', 'alley':
                          TestLookingUp();
                          "~Haven't thought about that place in a while. It was fun when I was a kid,
                          I was pretty good at Pac Man.~";
                      'house', 'abandoned':
                          if (self.knowAboutKiss) self.dontKillknowAboutKiss = true;
                          self.knowAboutKiss = true;
                          TestLookingUp();
                          "~You must mean the one behind the alley? Yeah, ah, you know. Hm. I never really hung out there.~";
                      'empire', 'movie':
                          TestLookingUp();
                          "~Empire, yeah, made during the golden age of Hollywood. If you ask me, they don't make ones like that anymore.~";
                      'wonder', 'woman', 'comic', 'comics':
                          TestLookingUp();
                          "~Wonder Woman was my idol. I wanted to be her. The closest thing I could do was start a collection of comics. But I sold them years ago. Funny how things work out.~";
                      'writing':
                          if (self.askAboutWritingTalk) {
                              TestLookingUp();
                              "~Like I said. Reading is about all I do now. Writing is hard. I'm tired of banging my head against the wall.~";
                          }
                          self.askAboutWritingTalk = true;
                          TestLookingUp();
                          "~Why does it matter? I like reading. Isn't that enough?~";
                      'floor':
                          TestLookingUp();
                          "~It's a little dirty. I'll get to it before my break.~";
                      'break':
                          TestLookingUp();
                          "~Yeah. I take them. When no one is around,~ she says, glaring at you.";
                      'reading':
                          TestLookingUp();
                          "~What am I reading? If you must know, it's On The Road. An old friend turned me on to it
                          a long time ago and I like rereading it every few years.~";
                      'beer', 'alcohol', 'booze':
                          TestLookingUp();
                          "~Sorry. There's no beer. A bunch of college kids came in and bought us out. You know how it is.~";
                      'city', 'town', 'sunnybrook':
                          if (self.askAboutTown) {
                              self.askAboutTown = false;
                              TestLookingUp();
                              "~I remember someone told me that you make about half your own
                              choices. I guess I could've done worst.~";
                          }
                          self.askAboutTown = true;
                          TestLookingUp();
                          "~I did leave this town for a bit, had that itch. But. Well. You know how it is.~";
                      'bus':
                          TestLookingUp();
                          "~The bus that runs to Springfield? It runs all night if you're looking to head
                          out that way.~";
                      'springfield':
                          TestLookingUp();
                          "~Can't tell you much about it. Springfield's pretty far. I don't get out of town very much.~";
                      'library':
                          TestLookingUp();
                          "~No one goes over to the library, not even me. The town let it fall apart. Never put any money into it.~";
                      'the', 'tavern':
                          TestLookingUp();
                          "~It closed down almost a year ago. I was sad when they shuttered its doors.
                          That place was a part of this town. Now. It's just going to rot.~";
                      'school', 'schooling':
                          TestLookingUp();
                          "~What about it? Did you go to school? Most of us do.~";
                      'college':
                          if (self.askAboutCooler) {
                              if (self.askAboutCollege) {
                                  TestLookingUp();
                                  "~There's one over in Springfield.~";
                              }
                              self.askAboutCollege = true;
                              TestLookingUp();
                              "~Yeah. There's one over in Springfield. I don't... Well. Hm.~";
                          }
                          TestLookingUp();
                          "~Yeah. There's one over in Springfield. I don't see too many people from over there.~";
                      'kids':
                          if (self.askAboutCooler) {
                              TestLookingUp();
                              "~Do you mean the college kids? They stopped by. We have cheap beer on sale.~";
                          }
                          TestLookingUp();
                          "~The kids in this town are out of hand. And I thought we were bad growing up.~";
                      'post', 'office':
                          TestLookingUp();
                          "~That old post office was a drop-off point for the mail. Back when it was run up
                          cow trails. At least that's what I heard.~";
                      'yard', 'junkyard', 'millers', 'miller', 'miller^s', 'miller?s':
                          TestLookingUp();
                          "~The junkyard closed down. Miller left, but never removed the cars from
                          back there. It's a real mess. Someone is going to have to clean it up.~";
                      'gas', 'station':
                          TestLookingUp();
                          "~Jerry practually runs the gas station now. Did real good for himself. Hm. Maybe in another life.~";
                      'pharmacy':
                          TestLookingUp();
                          "~What pharmacy? There hasn't been one in here in years.~";
                      'trailer', 'park':
                          TestLookingUp();
                          "~I don't get over to the trailer park much. I grew up in the sub. I'll probably die in it too.~";
                      'cold', 'drink', 'drinks', 'bottle', 'coke', 'cokes', 'cola', 'soda', 'pop':
                          TestLookingUp();
                          "~We got a few Cokes left. But I can't give them away for free.~";
                      'cooler':
                          self.askAboutCooler = true;
                          TestLookingUp();
                          "~Sorry. The cooler's almost empty. Some... college kids came in here
                          and bought the place out.~";
                      'name':
                          return AskForNameOldAmy();
                      'amy', 'herself', 'her', 'clerk', 'lady':
                          TestLookingUp();
                          if (self.askAboutSelf) {
                              "~You're going to leave like all the rest. Might as well go.~";
                          }
                          self.askAboutSelf = true;
                          self.askAboutSelfDaemon = true;
                          "~Look. You and everybody else that comes in here asks the same thing.
                          But you don't even know who I am. Hm. Like you're going to get to know me?~";
                      'owner':
                          TestLookingUp();
                          "~The owner comes and goes. He's a bit of a flake.~";
                      'snack', 'snacks', 'bar', 'bars', 'box', 'junk', 'food', 'chocolate', 'candy':
                          TestLookingUp();
                          "~Uh. That stuff has done nothing good for me. It just added to the pounds. And after all the years I've worked here.~";
                      'yukypah', 'heef', 'statue':
                          TestLookingUp();
                          "~Hm. That guy. Why they keep that up, I don't know.
                          The kids paint over it all the time.~";
                      'convenience', 'drug', 'store', 'work', 'job', 'shop', 'place':
                          self.askAboutStoreTalk = true;
                          TestLookingUp();
                          "~When it's slow like this I like to get in a bit of reading. It keeps my mind occupied.~";
                      'scientist':
                          TestLookingUp();
                          "~No. No one has stopped by like that. Sorry.~";
                      'sam':
                          self.askAboutSamTalk = true;
                          TestLookingUp();
                          "~Isn't he your friend? I heard he moved in with you - with his wife.
                          That must be tough. Help that guy out before he destroys your friendship.~";
                      'judy':
                          TestLookingUp();
                          "~Judy is a great lady, works hard over at the bowling alley too.
                          Hm. She likes to stop by, but I still don't see her enough.~";
                      'mark', 'attendant':
                          TestLookingUp();
                          "~Kids nowadays. I doubt that Mark even knows how easy he has it over there.
                          Jerry's told me about that kid. Hm. A real slacker.~";
                      'past', 'things':
                          TestLookingUp();
                          "~Are you trying to be funny? Because you're not. You know things never worked out. Hm. So move on.~";
                      'tom':
                          TestLookingUp();
                          print "~That guy's weird. He always thinks the world is about to end or
                          that aliens are invading. Hm.
                          You might want to find something around town to give him. To make him happy";
                          if (plate.showToAmy) ". You know, like that plate with the alien on it.~";
                          ".~";
                      'guy':
                          TestLookingUp();
                          print "~You mean Tom. That guy's weird. He always thinks that world is about to end or
                          that aliens are invading. Hm.
                          You might want to find something around town to give him. To make him happy";
                          if (plate.showToAmy) ". You know, like that plate with the alien on it.~";
                          ".~";
                      'friend', 'bum', 'ed', 'eddie', 'old':
                          TestLookingUp();
                          "~Yeah. I made friends with this older guy around here. He died a long time ago,
                          but he taught me a lot about myself. Wish he was here. Drank too hard.~";
                      'time', 'machine': "You better keep that bit of information to yourself.";
                      'melville', 'melvill':
                          TestLookingUp();
                          "~They closed down all the 'plants over there. And when the factories closed
                          so did The Tavern. Even the owner of this place says it's hard to keep things
                          going. Hm.~";
                      'current', 'date', 'year':
                          TestLookingUp();
                          "~Another election year. I don't know. They say, 'This time it's the most
                          important time to vote.' But I've been hearing that my whole life.~";
                      'doorman':
                          TestLookingUp();
                          "~Whoever does the hiring for that place really know how to pick 'em.
                          Every doorman to work that building has been a real piece of work. I'd
                          just stay away from him.~";
                     'complex', 'high-rise', 'highrise', 'highland', 'towers', 'apartment', 'apartments':
                          TestLookingUp();
                          "~I always hoped that one day I'd move in there. But now look at the place.
                          It went downhill and that doorman's a drunk.~";
                      'jerry':
                          if (self.knowAboutKiss) {
                              self.knowAboutKiss = false;
                              TestLookingUp();
                              "She snaps, ~What about him? I didn't do anything in that house.~";
                          }
                          TestLookingUp();
                          "~Jerry runs things over at the gas station, even though he doesn't own it. Hm.~";
                      'phil', 'phill':
                          TestLookingUp();
                          "~There's no Phil that lives around here.~";
                      'nancy', 'punk':
                          TestLookingUp();
                          "~Nancy? No. No one lives around here like that. When I was younger there was
                          someone named Nancy that lived here. But I'm not sure what happened to her.~";
                      'nick', 'biker':
                          TestLookingUp();
                          "~You mean the biker?. He's pretty cool. Even went out to L.A. and made it big
                          writing music. Hm.~";
                      'tattoo', 'tatoo', 'tattoos', 'tatoos', 'tattoing':
                          TestLookingUp();
                          "~Nick runs the tattoo shop. It use to be an art gallery, but the curator
                          ran into a windfall. Hm. Told me she was going to Europe.~";
                      'madame', 'sorra', 'gypsy', 'fortune-teller', 'fortune', 'teller':
                          TestLookingUp();
                          "~In all the time I've worked here she's never come in this place.
                          I don't think she ever leaves her shop.~";
                      'cigarette', 'cigarettes', 'cig', 'cigs', 'fag', 'fags', 'smokes':
                          TestLookingUp();
                          "~You know how it is. Everybody's trying to go healthy. We recently stopped selling cigarettes.~";
                      'change', 'quarters', 'quarter':
                          TestLookingUp();
                          "~Sorry. You need to buy something if I'm gonna make change.~";
                      'book', 'paperback':
                          TestLookingUp();
                          if (self.askAboutBook) self.dontKillaskAboutBook = true;
                          self.askAboutBook = true;
                          "~It's On The Road, by Kerouac. Do you know it? Hm.~";
                      'on':
                          TestLookingUp();
                          "~I don't know. There's something about this book. It's a bit dated,
                          but it reminds me of a simpler time.~";
                      'kerouac', 'kerou':
                          TestLookingUp();
                          "~He was a great writer. An old friend turned me on to him. But he was before my time.~";
                      'ufo', 'ufos':
                          TestLookingUp();
                          "~Tom's into all that, but I don't believe a word of it. We're not monkeys who were
                          meant to dig gold for our alien overlords. That's crazy.~";
                      'alien', 'aliens':
                          TestLookingUp();
                          "~I don't believe in them, but they're popular nowadays. I figure it's
                          because we live in a modern society. Everybody sees things through that
                          alien lens.~";
                      'diner':
                          TestLookingUp();
                          "~Don't eat anything in there. That place is disgusting. I had breakfast once. I couldn't believe it gave me the runs for a week.~";
                      'me', 'self', 'yourself':
                          TestLookingUp();
                          "~Can't say I ever got to know you, but you've always treated me well every time you're in here. Better than some.~";
                      'thing':
                          TestLookingUp();
                          if (plate.showToAmy) "~How about something like that plate you showed me. The one with the alien on it.~";
                          "~I'm not sure what that guy would go for, but there has to be something around this town.~";
                      'him', 'himself', 'her', 'herself', 'them':
                          "At the moment, even the simplest questions are confusing.";
                      'covid', 'bug', 'corona', 'coronavirus', 'virus', 'dad': "~Oh. Don't get me started. I think my Dad down in Florida has it.~";
                      default:
                          return (OldAmyResponse());
                  }
              Tell:
                  if (self.lookUp) self.dontKillLookUp = true;
                  self.lookUp = true;
                  iAmyConversation++;
                  wn = consult_from;
                  w1 = NextWord();
                  switch(w1) {
                      'hi', 'hello', 'hola', 'greetings':
                          <<Hello self>>;
                      'snack', 'snacks', 'bars', 'missing', 'box', 'bar', 'junk', 'food', 'chocolate', 'candy':
                          TestLookingUp();
                          "~What about the snacks? We've got lots of them.~";
                      'yes', 'please', 'ok':
                          TestLookingUp();
                          if (self.askAboutSelfDaemon) "~I doubt that.~";
                          if (self.askAboutBook) "~Then you can appreciate what he did. Not may can.~";
                          "~I'm glad you're happy. At least someone is.~";
                      'no':
                          TestLookingUp();
                          if (self.askAboutSelfDaemon) "~At least you're honest.~";
                          if (self.askAboutBook) "~You're like everybody else in this town. But it's what I've come to expect.~";
                          "~Try not to be down. Life should be a joy. Or at least you'd think.~";
                      'good':
                          TestLookingUp();
                          "~I'm happy for you.~";
                      'bad':
                          TestLookingUp();
                          "~That'll happen.~";
                      'sorry':
                          TestLookingUp();
                          "~Yeah... Hm. Okay, sure.~";
                      'time', 'machine', 'note', 'notes', 'house', 'abandoned':
                          "She's preoccupied and doesn't care.";
                      'him', 'himself', 'her', 'herself', 'them':
                          "At the moment, even the simplest statements are confusing.";
                      'thanks', 'thank': "~Yeah. Sure.~";
                      'goodbye', 'goodby', 'good-bye', 'bye', 'cheerio':
                          TestLookingUp();
                          if (self.lookUp) {
                              self.lookUp = false;
                              iAmyLookUp = 0;
                              "~Yeah. Bye,~ she says, turning back to her book.";
                          } else {
                              "~Yeah. Bye,~ she says, not even looking up.";
                          }
                      'mothership':
                          "~You might want to talk to Tom about that. I bet you two have that in common.~";
                      'evict', 'eviction', 'sam', 'trailer', 'me', 'self', 'yourself':
                          if (self.toldEvict) "You've already told her about that.";
                          self.toldEvict = true;
                          TestLookingUp();
                          "You tell her about the situation over the trailer park.^
                          ^~You need to figure that one out. Living on the street won't do you. I've already lost one friend that way.~";
                      'tom':
                          TestLookingUp();
                          if (mapleRoad.firstTime) "~That guy is just out there. Stay away from him if you can.~";
                          print "You tell her Toms freaking out down the street.^
                          ^~Oh, no. He caught up with you? He'll stop you in order to make his point.
                          You might want to find something around town to give him. To make him happy";
                          if (plate.showToAmy) ". You know, like that plate with the alien on it.~";
                          ".~";
                      'covid', 'bug', 'corona', 'coronavirus', 'virus': "~Come on. What do you know that the rest of us don't?~";
                      default:
                          return (OldAmyResponse());
                  }
          ],
          orders [;
              Hello:
                  <<Hello self>>;
              Strong: "The clerk ignores you.";
          ],
          knowAboutKiss false,
          dontKillknowAboutKiss false,
          dontKillLookUp false,
          amyReturn false,
          seensnacks false,
          askAboutWritingTalk false,
          nameSecondTime false,
          askAboutSelf false,
          lookUp false,
          askAboutPops false,
          askAboutDiana false,
          askAboutStoreTalk false,
          askAboutTown false,
          askAboutSamTalk false,
          askAboutCooler false,
          askAboutCollege false,
          askAboutBook false,
          dontKillaskAboutBook false,
          askAboutSelfDaemon false,
          toldEvict false,
    has   animate female concealed;

  [ OldAmyResponse;
        TestLookingUp();
        iAmyConversation++;
        if (iAmyConversation > 9) {
            iAmyConversation = 0;
            "~Uh. Can't you see I got a lot of things to do? Talking all night to you isn't one of them.~";
        }
        if (iAmyConversation > 4) "~Look. I don't care about that.~";
        "~Not sure about that. Maybe I can help you with something else.~";
  ];

  [ TestLookingUp;
        if (convenienceStoreOldAmy.lookUp) convenienceStoreOldAmy.dontKillLookUp = true;
        if (convenienceStoreOldAmy.lookUp == false) {
            convenienceStoreOldAmy.lookUp = true;
            print (string) random("~Yeah,~ the clerk says, raising her head to look up at you.^^",
            "~What?~ the clerk asks, raising her head to look up at you.^^",
            "~Hm,~ the clerk says, raising her head to look up at you.^^",
            "~Yes,~ the clerk says, raising her head to look up at you.^^",
            "~Yeah,~ the clerk says, raising her head to look up at you.^^");
        }
  ];

  [ AskForNameOldAmy;
        TestLookingUp();
        "~Are you playing around or something? You know my name is Amy.~";
  ];
