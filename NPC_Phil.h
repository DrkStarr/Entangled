! Phil can end up retiring in Flordia
! or if he's intriged, he'll retire in Arizona, only to end up
! being arrested for trespassing in Area 51. A closed airforce base.
!
! Strength: Helping People, Customer Service, Gets along
! Weakness: Educations, never got one. Chain smoker, but it doesn't kill him early.
!
!
! Age: 52
! Born: 1928
! Great Depression: 1929 - 1939
! Grew up in Chicago
! 1940: Age 12: Running numbers for gansters
! 1941: Age 13: Peral Harbor
! 1944: Age 16: Bussing Tables
! 1945: Age 17: The Bomb
! 1947: Age 19: Working in a Bar
! For 30 years Phil has beed tending bar, he started at 22
! He's made great money over the years and believes he's doing a good things
! Phil is a chain smoker. Even when washing dishes he tries to keep one going.
!
! , he says taking a drag off the cigarette before returning to the dishes.
!
! Ask Phil about Scientist,
!

! Character Diamond
! 1: Optimistic
! 2: Down To Earth - Rooted In The 50s
! 3: Can Be Rude - (Guilt - Holds A Secret - To Cover Up The Guilt - Brash)
! 4: Ambitious - Wants To Run A Business Like Bob After Retiring From The Bar
! 5: Awestruck Of Bob - The Owner

!
! ---------------------------------------------------------------------------- !
!       PHIL. 08/11/16
!

  Object  -> alleyBarPhil "bartender"
    with  name 'phil' 'bartender' 'man' 'guy' 'dude' 'old' 'older' 'phill',
          describe [;
              rtrue;
          ],
          daemon [;
              ! Used to get the bartender to respond to his generic response
              ! If the bartender asks the player if they want a drink, the game
              ! listens for a response from the PC

              if (self.askForDrink) {
                  iAskWait++;
              }
              if (self.dontKillAskForDrink) {
                  self.dontKillAskForDrink = false;
              } else {
                  if (iAskWait > 1) {
                      iAskWait = 0;
                      self.askForDrink = false;
                  }
              }

              if (self.askForSecondDrink) {
                  iAskSecondWait++;
              }
              if (iAskSecondWait > 1) {
                  iAskSecondWait = 0;
                  self.askForSecondDrink = false;
              }
          ],
          before [ w1;
              AskCreatureFor:
                  wn = consult_from;
                  w1 = NextWord();
                  switch (w1) {
                      'cigarette', 'cigarettes', 'cig', 'cigs', 'fag', 'fags', 'smokes':
                          if (self.askForCig) {
                              print "~Like I said. ";
                          } else {
                             print "~Sorry. ";
                          }
                          self.askForCig = true;
                          print "I bought the last pack. We're all out, and you're not getting one of mine";
                          return PhilWash();
                      'cold', 'drink', 'drinks', 'bottle', 'pitcher', 'alcohol', 'booze', 'beer':
                          if (dollarBill in player)
                              "~I can see you have some cash, but you don't want this stuff. The taps
                              aren't the cleanest. You'd regret it.~";
                          "~I don't see any money in your hand,~ the bartender complains.";
                      'whiskey', 'whisky':
                          if (dollarBill in player)
                              "~You look like a nice person, so I'll tell you the truth. We water it down.
                              You don't want the whiskey.~";
                          "~I don't see any money in your hand,~ the bartender complains.";
                      'scotch', 'vodka':
                          print "~Sorry. We don't server that kind of alcohol. You might want to try over at The Tavern";
                          return PhilWash();
                      'food', 'burger', 'burgers':
                          if (dollarBill in player) {
                              print "~Look. It's a big burger. Almost a half a pound, fried up on a bun. Along with some fries. But it's $2.50";
                              return PhilWash();
                          }
                          if (self.knowBurgers) "~If you show me some coin, I'll go in the back and cook something up.~";
                          self.knowBurgers = true;
                          print "~We got some burgers in the back. If you want one, I gotta cook them up";
                          return PhilWash();
                      'name':
                          return AskForNamePhil();
                      'change', 'quarters', 'quarter':
                          "~I'd like to, but what are you going to buy that requires change?~";
                  }
                  return PhilResponse();
              AskTo:
                  switch(second) {
                      t_bowl:
                          print "~Looking to entertain an old man? I got stuff to do. I'm working";
                          return PhilWash();
                      t_drink:
                          "~I'm good. I had a few before I came in,~ the bartender smiles.";
                  }
                  return PhilResponse();
              Enter, Go:
                  "You're already here.";
              Examine:
                  "The bartender has a bit of gray showing around the temples. He keeps busy
                  by washing an endless amount of dirty glasses and old pitchers.";
              Talk:
                  print "[You can try ";
                  if (self.askAboutBar) {
                      print "ASK ABOUT BOWLING ALLEY";
                  } else {
                      print "ASK ABOUT BAR";
                  }
                  print " or ";
                  if (self.samFirstTime) {
                      if (self.judyFirstTime) {
                          print "ASK ABOUT BOB";
                      } else {
                          print "ASK ABOUT JUDY";
                      }
                  } else {
                      print "ASK ABOUT SAM";
                  }
                  ". There are also lots of other things too.]";
              Hello:
                  "~Need anything?~ the bartender asks, looking up for a second before returning to his dishes.";
              Eat, Taste:
                  "What? Are you a cannibal? I know you're not that hungry.";
              WaveObject:
                  print "~Hi there, glad to see someone trying to be nice in this day and age";
                  return PhilWash();
              Take:
                  "You know he's not an object?";
              Attack, Blow, Burn, Buy, Climb, Close, Cut, Dig, Drink, Eat, Empty, Enter, Exit, GetOff, Go, JumpOver, Kick, Kiss, Listen, LookUnder, Open:
                  "You can't do that. He's behind the bar.";
              Push, PushDir, Pull, Read, Remove, Rub, Search, Set, SetTo, SmellNoun, Squeeze, Swing, SwitchOn, SwitchOff, Take, Talk, Taste, Tie, Touch, Transfer, Turn, Unlock, Wave:
                  "You can't do that. He's behind the bar.";
          ],
          life [ w1;
              Answer:
                  switch(noun) {
                      t_hi: <<Hello self>>;
                      t_yes: return AnswerYesPhil();
                      t_no: return AnswerNoPhil();
                      t_good: if (self.answerGood) "~Glad to hear it.~";
                              self.answerGood = true;
                              if (self.askForDrink) self.dontKillAskForDrink = true;
                              self.askForDrink = true;
                              print "~Glad to hear it. Let's celebrate with a drink";
                              return PhilWash();
                      t_bad: if (self.answerGood) "~Sorry to hear that.~";
                             self.answerGood = true;
                             if (self.askForDrink) self.dontKillAskForDrink = true;
                             self.askForDrink = true;
                             print "~Sorry to hear that. Maybe a drink will help";
                             return PhilWash();
                      t_sorry: print "~Don't be. We're all friends here";
                               return PhilWash();
                      t_thanks: print "~Sure. If I helped";
                                return PhilWash();
                      default:
                          return PhilResponse();
                  }
              Ask:
                  wn = consult_from;
                  w1 = NextWord();
                  switch (w1) {
                      'halloween':
                          if (self.askAboutHalloween) "~Yeah. Kids are spoiled. You wait to see what happens.~";
                          self.askAboutHalloween = true;
                          print "~We didn't get candy for Halloween when I was a kid, it was the Depression, and we worked for what we had.
                          Kids nowadays are spoiled";
                          return PhilWash();
                      'samhain':
                          if (self.askAboutSamhain) "~Don't bother me about that. If you are into it, go talk to a hippie.~";
                          self.askAboutSamhain = true;
                          print "~Samhain? What do you think I am, some sort of hippy? Talk to Sarah over at the gallery.
                          I'm sure she could chew your ear off about that";
                          return PhilWash();
                      'candy':
                          "~Yeah, I don't eat the stuff. Never had it when I was a kid, don't need it as an adult.~";
                      'bar':
                          self.askAboutBar = true;
                          print "~Every bowling alley has to have a bar, am I right? This place has been
                          a fixture in this town since the '50s";
                          return PhilWash();
                      'bob', 'boss', 'owner':
                          print "~Bob runs the place. I mean the bowling alley and all. But we're a little short
                          staffed right now, so he's been handling the day shift";
                          return PhilWash();
                      'cigarette', 'cigarettes', 'cig', 'cigs', 'fag', 'fags', 'smokes':
                          self.askForCig = true;
                          print "~Usually we have some. But I bought the last pack. Sorry. We're all sold out";
                          return PhilWash();
                      'customer', 'customers':
                          print "~The people around here keep to themselves, present company excluded, but they tip well";
                          return PhilWash();
                      'current', 'date', 'year':
                          print "~Times are going to hell. Take a look at these kids nowadays. No respect.
                          Always listening to loud rock music. Yeah. They're going straight down the drain";
                          return PhilWash();
                      'drink', 'drinks', 'bottle', 'alcohol', 'booze':
                          if (dollarBill in player)
                              "~You look like a nice person, so I'll tell you the truth. We water it down.
                              You don't want the whiskey.~";
                          if (alleyBarPhil.askForDrink) alleyBarPhil.dontKillAskForDrink = true;
                          alleyBarPhil.askForDrink = true;
                          print "~If you have cash, I'd gladly pour you some";
                          return PhilWash();
                      'pitcher', 'beer':
                          if (dollarBill in player)
                              "~I can see you have some cash, but you don't want this stuff. The taps
                              aren't the cleanest. You'd regret it.~";
                          if (alleyBarPhil.askForDrink) alleyBarPhil.dontKillAskForDrink = true;
                          alleyBarPhil.askForDrink = true;
                          print "~If you had some cash I'd pour you one. But you don't want to drink from these taps";
                          return PhilWash();
                      'taps':
                          print "~You know how it is, the bar's been around since the '50s.
                          They're original";
                          return PhilWash();
                      'scotch', 'vodka':
                          print "~Sorry. We don't serve that kind of alcohol";
                          return PhilWash();
                      'food', 'burger', 'burgers', 'kitchen':
                          if (self.knowBurgers) "~If you show me some coin, I'll go in the back and cook something up.~";
                          self.knowBurgers = true;
                          print "~We got some burgers in the back. If you want one, I gotta cook them up";
                          return PhilWash();
                      'judy':
                          if (self.judyFirstTime) {
                              self.believesConspiracy = true;
                              "~I'm sorry she doesn't work here. That's odd,~ he says, drifting off
                              in thought before returning to wash some glasses.";
                          }
                          self.judyFirstTime = true;
                          print "~No, I can't say that I've heard of her.~
                          ^^You tell him that she works here.
                          ^^~That's strange,~ he says, ~Bob and I cover the shifts around here.
                          We're the only two that work the bar. Bob's the owner";
                          return PhilWash();
                      'house', 'abandoned':
                          print "~The beat-up house behind this place? Depression Era that one is. Strong
                          as the stone it's made from, but the wood is rotten to the core. It would've
                          lasted forever if someone would've taken care of it";
                          return PhilWash();
                      'library':
                          print "~Didn't have the time to read when I was younger, so I didn't make it a habbit.
                          I've never been over there";
                          return PhilWash();
                      'time', 'note', 'notes': "You better keep that information to yourself.";
                      'covid', 'bug', 'corona', 'coronavirus', 'virus': "You should keep that information to yourself.";
                      'mabel':
                          print "~The lady that works the pharmacy? She's cold I can tell you that. I've tried
                          to ask her out, you know she can't be getting hit on all the time, not in a town
                          like this, but she just blew me off. She's gonna end lonely";
                          return PhilWash();
                      'pharmacy':
                          print "~I've gone over there to talk to Mabel, but she's a cold fish";
                          return PhilWash();
                      'name':
                          return AskForNamePhil();
                      'sam':
                          if (self.samFirstTime) "~Look around. He's not here. Maybe your friend is running late. People do that you know?~";
                          self.samFirstTime = true;
                          if (self.askForDrink) self.dontKillAskForDrink = true;
                          self.askForDrink = true;
                          print "~Sam? Sorry. Don't know him. Haven't seen anybody like that tonight either.
                          Maybe he'll show up a little later. Why don't you have a drink?";
                          return AskMultiAboutSam();
                      'trailer', 'park':
                          print "~A lot of people make it over here from the trailer park. It's not too far to
                          walk. Good people too. They'll help you out if you need it";
                          return PhilWash();
                      'school', 'schooling':
                          print "~Never got that far in school. I was born at the beginning of the depression. But I can do simple
                          math and that's all I need for working at the alley";
                          return PhilWash();
                      'college':
                          print "~Well since I didn't graduate high school, I never made it to college.
                          But I never wanted to go";
                          return PhilWash();
                      'post', 'office', 'mail':
                          print "~The owner sends his mail here, so we get all sorts of stuff from the
                          post office. Wish he wouldn't. I hate having it in the way";
                          return PhilWash();
                      'the', 'tavern':
                          print "~That place is a little loud for me. What with the bands or P.A. It's relaxing here. People can mingle on their own";
                          return PhilWash();
                      'work', 'job', 'shop', 'place', 'bowling', 'alley':
                          print "~Working at the alley here can be hard with the long hours and standing on
                          your feet, but you get to meet some great people";
                          return PhilWash();
                      'yard', 'junkyard', 'millers', 'miller', 'miller^s', 'miller?s':
                          print "~I've never been over there. Heard the dog that protects the place is mean as hell,
                          but I wouldn't know";
                          return PhilWash();
                      'dog', 'doberman':
                          print "~I've heard that dog's mean. But I don't go over to the junkyard";
                          return PhilWash();
                      'gas', 'station':
                          "~I use to work in a gas station when I was younger and waited on the customers.
                          Filled their tanks. Washed their windshields. Not like they do today. No one cares
                          about customer service.~";
                      'city', 'town', 'sunnybrook':
                          print "~I like it here. This might even be my last stop. But I don't know. I've traveled a lot. I might keep on trucking";
                          return PhilWash();
                      'travel':
                          print "~I've been to a lot of places since after the war. The bomb fell in '45, so I miss it. But I've been all around
                          California, down through Louisiana, and across the Caribbean. Settled here in the '70s";
                          return PhilWash();
                      'war', 'bomb':
                          print "~I had turned 17 by the time we dropped the bomb. I just missed it. I was going to enlist, even got my Mom to agree, then one day it was over";
                          return PhilWash();
                      'california':
                          print "~I was there in the '50s when they started building up L.A. It was nothing like it is now. I can't believe all those hippies are trying to change it";
                          return PhilWash();
                      'caribbean', 'barbados', 'trinidad', 'tobago':
                          print "~Well. I saw all the islands east of the Dominican Republic and went down to Trinidad and Tobago, working the tiki bars on the local beaches. But I like Barbados the most. Excellent diving. Clear-blue reefs";
                          return PhilWash();
                      'louisiana', 'voodoo':
                          print "~Some strange voodoo goes on down there. I had fun for a bit, but moved on before I got caught up in it";
                          return PhilWash();
                      'tiki', 'bars', 'tiki-bar':
                          print "~Tiki bars litter the Caribbean. I made good cash down there when I was younger";
                          return PhilWash();
                      'scientist', 'mark', 'tom':
                          print "~I haven't seen anybody around like that";
                          if (self.samFirstTime || self.judyFirstTime) print ". You do know some strange people";
                          return PhilWash();
                      'whiskey', 'jack', 'daniel', 'daniels', 'daniel^s', 'daniel?s', 'whisky':
                          print "~We don't sell that much of it. You know, most of our customers go for the beer.
                          It's cheaper. Plus, people can drive away after drinking a few";
                          return PhilWash();
                      'amy', 'clerk':
                          print "~The girl that works over at the drug store? I don't go over
                          there. That place is a rip-off";
                          return PhilWash();
                      'bum', 'ed', 'eddie':
                          print "~This isn't a charity, so they don't let that guy in here";
                          return PhilWash();
                      'doorman':
                          print "~The one that works over at Highland? He's meaner than Harry, at least
                          he never comes in here";
                          return PhilWash();
                      'complex', 'high-rise', 'highrise', 'highland', 'towers', 'apartment', 'apartments':
                          print "~I was invited to a party over there once by a customer of mine. But what
                          did that doorman do? He wouldn't let me in. Burned my hide";
                          return PhilWash();
                      'harry', 'old', 'guy':
                          print "~He's another snaggletooth that I'd rather not see around here";
                          return PhilWash();
                      'jerry', 'attendant':
                          print "~The kid that works over at the gas station? He seems to be decent,
                          but most kids are just getting out of hand";
                          return PhilWash();
                      'nancy', 'punk', 'girl':
                          "~I don't know about kids these days. Disrespecting everyone. Where's it going to go?~";
                      'madame', 'sorra', 'gypsy', 'fortune-teller', 'fortune', 'teller':
                          print "~She's a bit of a recluse. Though she's only trying to make a living like everybody else";
                          return PhilWash();
                      'nick', 'pretty', 'boy':
                          print "~That kid's no better than any other. And a con for a bartender at that.
                          As far as I can tell he's a musician and not in it for the long haul. Where's the
                          sacrifice nowadays";
                          return PhilWash();
                      'phil', 'phill', 'bartender', 'himself', 'him', 'man', 'dude':
                          print "~Don't have much to say about myself. I'm just a hard working bartender";
                          return PhilWash();
                      'art', 'gallery':
                          if (self.askAboutGallery) {
                              print "~How Sarah keeps that place open I'll never know. Doesn't sell much from what I hear";
                              return PhilWash();
                          }
                          self.askAboutGallery = true;
                          print "~The place is run by Sarah. A bit of a hippy. How she keeps it open I'll never know. I don't go for that lifestyle";
                          return PhilWash();
                      'sarah', 'curator', 'hippie':
                          print "~Sarah is nice and all, but you know hippies. I don't believe in the whole peace and love thing";
                          return PhilWash();
                      'convenience', 'drug', 'store':
                          print "~That place is overpriced. And that girl? Amy? Always reading.
                          I hope she does something with her life";
                          return PhilWash();
                      'yukypah', 'heef', 'statue':
                          print "~One should appreciate the statues of old. They come from another era when people respected their elders";
                          return PhilWash();
                      'bus':
                          print "~I know the bus will take you to Melville, but I have my car";
                          return PhilWash();
                      'melville', 'melvill':
                          print "~Yeah a few people from there stop by now and then,
                          but they don't tip well. I can't hold it against them but
                          it would be nice if they were a little more giving";
                          return PhilWash();
                      'change', 'quarters', 'quarter':
                          "~I'd like to, but what are you going to buy that requires change?~";
                      'plug', 'spark', 'sparkplug', 'fuse':
                          print "~You lookin' for a spark plug? No. You won't find anything like that 'round here.
                          I'd go over to the gas station and ask 'round there";
                          return PhilWash();
                      'shard', 'crystal', 'crystals':
                          print "~You one of those new agers or something? I never really got into that
                          scene. Those people seem fake, always too happy for me. Kind of like the curator
                          that runs the gallery here in town";
                          return PhilWash();
                      'vacuum', 'tube', 'tubes':
                          if (self.askAboutTube) {
                              print "~Talk to the bartender over at The Tavern";
                              return PhilWash();
                          }
                          self.askAboutTube = true;
                          print "~Vacuum tube? You know who's into them? The guy that works The Tavern.
                          He's some sort of musician. Not a bartender as I see it";
                          return PhilWash();
                      'glass', 'glasses', 'dish', 'dishes':
                          print "~Gotta keep the glasses clean. Might be a pain, but I try to stay on top of it";
                          return PhilWash();
                      'tattoo':
                          print "~What? A tattoo shop here in town? You must be mistaken. There's nothing like that around here";
                          return PhilWash();
                      'alien', 'aliens':
                          "~I bet you watch 'In Search Of.' Looks like Leonard Nimoy has sold you on them, hun?~";
                      'kids':
                          print "~They come in here all the time. Love to play that arcade machine. Who knows where they get the quarters. Bob's making a killing off that thing";
                          return PhilWash();
                      'arcade', 'machine', 'game':
                          print "~Yeah, arcade machines. Those things are a fad. I bet they won't be more popular than the hola-hoop";
                          return PhilWash();
                      'people':
                          print "~Yeah. I've made more than one friend for life working behind a bar";
                          return PhilWash();
                      'smoke':
                          print "~Yeah. The air can get a little thick. Good for the lungs though. Works them out";
                          return PhilWash();
                      'me', 'self', 'yourself':
                          print "~I can't say I've seen you around";
                          return PhilWash();
                      'him', 'himself', 'her', 'herself', 'them':
                          "At the moment, even the simplest questions are confusing.";
                      default:
                          return PhilResponse();
                  }
              Tell:
                  wn = consult_from;
                  w1 = NextWord();
                  switch(w1) {
                      'hi', 'hello', 'hola', 'greetings':
                          <<Hello self>>;
                      'yes', 'please', 'ok':
                          return AnswerYesPhil();
                      'no':
                          return AnswerNoPhil();
                      'good':
                          if (self.answerGood) "~Glad to hear it.~";
                          self.answerGood = true;
                          if (self.askForDrink) self.dontKillAskForDrink = true;
                          self.askForDrink = true;
                          print "~Glad to hear it. Let's celebrate with a drink";
                          return PhilWash();
                      'bad':
                          if (self.answerGood) "~Sorry to hear that.~";
                          self.answerGood = true;
                          if (self.askForDrink) self.dontKillAskForDrink = true;
                          self.askForDrink = true;
                          print "~Sorry to hear that. Maybe a drink will help";
                          return PhilWash();
                      'sorry':
                          print "~Don't be. We're all friends here";
                          return PhilWash();
                      'time', 'machine', 'note', 'notes', 'house', 'abandoned', 'date', 'year':
                          "You better keep that information to yourself.";
                      'covid', 'bug', 'corona', 'coronavirus', 'virus': "You should keep that information to yourself.";
                      'him', 'himself', 'her', 'herself', 'them':
                          "At the moment, even the simplest statements are confusing.";
                      'thanks', 'thank':
                          print "~Sure. If I helped";
                          return PhilWash();
                      'cigarette', 'cigarettes', 'cig', 'cigs', 'fag', 'fags', 'smokes':
                          print "~Ah. I'd like to help you, but I'm not supposed to open the register. Only for a sale";
                          return PhilWash();
                      default:
                          "~I don't know about that. Anything else I can help you with?~";
                  }
          ],
          orders [;
              Give:
                  if (noun == alleyBarBottle) {
                      if (dollarBill in player)
                          "~You look like a nice person, so I'll tell you the truth. We water it down.
                          You don't want the whiskey.~";
                      "~I don't see any money in your hand,~ the bartender complains.";
                  }
                  if (noun == alleyBarBeer) {
                      if (dollarBill in player)
                          "~I can see you have some cash, but you don't want this stuff. The taps
                          aren't the cleanest. You'd regret it.~";
                      "~I don't see any money in your hand,~ the bartender complains.";
                  }
                  if (noun == alleyBarCigarette) "~These are the last smokes in the place. Go find your own.~";
                  "~Sure. I'd love to give you that,~ he says sarcastically, ~now what were we talking about?~";
              Hello:
                  <<Hello self>>;
              Open:
                  if (noun == alleyBarBottle) "~Not before you buy it.~";
                  if (noun == alleyBarRegister) "~I hope you're not planning to rob us. You really don't look the part.~";
                  "~Oh yeah. I'd love to open that,~ he says sarcastically, ~now what were we talking about?~";
              Push:
                  if (noun == alleyBarStool) "~They're fine where they are. Leave 'em alone.~";
              Rub:
                  if (noun == alleyBarBottle || noun == alleyBarBeer) "~There's nothing wrong with that.~";
                  if (noun == alleyBarGlasses) "~What's the rush? These things are getting cleaned.~";
                  if (noun == alleyBarShelf) "~That's already clean, can't you tell?~";
                  if (noun == alleyBarStool) "~There's nothing wrong. Why don't you clean them if it's such a problem.~";
                  if (noun == alleyBarCounter) "~What's your problem? You could eat off this thing.~";
                  "~Absolutely. I'd love to clean that,~ he says sarcastically, ~now what were we talking about?~";
              Take:
                  if (noun == alleyBarBottle || noun == alleyBarBeer) "~If you want to buy something produce the coin.~";
                  if (noun == alleyBarGlasses || noun == alleyBarShelf) "~What? Are you my boss now? I know how to do my job. Move on.~";
                  if (noun == alleyBarStool) "~I know what I'm doing. Mind your own business.~";
                  if (noun == alleyBarCigarette) "~What? I'm not smoking them fast enough for you?~";
                  "~I have better things to do.~";
              Strong: "The bartender ignores you.";
          ],
          askForCig false,
          askForDrink false,
          dontKillAskForDrink false,
          knowBurgers false,
          answerGood false,
          samFirstTime false,
          judyFirstTime false,
          nameFirstTime false,
          believesConspiracy false,
          askForSecondDrink false,
          askAboutBar false,
          askAboutTube false,
          askAboutGallery false,
          askAboutHalloween false,
          askAboutSamhain false,
    has   animate male concealed;

  [ PhilResponse;
        if (alleyBarPhil.askForDrink) alleyBarPhil.dontKillAskForDrink = true;
        alleyBarPhil.askForDrink = true;
        "~Not sure about that. Maybe you want a drink?~";
  ];

  [ PhilWash;
        iPhilWashDish++;
        if (iPhilWashDish > 2) {
            iPhilWashDish = 0;
            alleyBar.shutOffDaemon = true;
            ",~ he says, taking a drag off his cigarette before returning to the dishes.";
        } else {
            ".~";
        }
  ];

  [ AskForNamePhil;
        SelfPlayer.knowPhil = true;
        if (alleyBarPhil.nameFirstTime) "~Ah. Phil. What are you doing? Writing a book or something?~";
        alleyBarPhil.nameFirstTime = true;
        iPeople++;
        print "~Phil's the name. Been working these taps for the past few years";
        return PhilWash();
  ];

  [ AnswerYesPhil;
        if (alleyBarPhil.askForDrink) {
            alleyBarPhil.askForSecondDrink = true;
            if (alleyBarBeer.tryToBuy) "~Look. Stop screwing around. They're a buck a pitcher.~";
            alleyBarBeer.tryToBuy = true;
            print "~That'll be a buck a pitcher";
            return PhilWash();
        }
        "~Sure. What is it?~";
  ];

  [ AnswerNoPhil;
        if (alleyBarPhil.askForSecondDrink) "~Looks like you're wasting my time.~";
        if (alleyBarPhil.askForDrink) "~Oh. Well I guess I can't help you.~";
        print "~Who am I to argue";
        return PhilWash();
  ];
