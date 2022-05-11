! Amy should have frizzy hair
!
!
! Conan the Barbarian Comic # 115 October 1980
! The Savage Sword of Conan Magazine # 57 - not used
! Eerie Magazine # 115
! Sgt. Rock Comic # 345
! Star Trek Comic # 7
! X-Men Comic # 138
! The Unknown Soldier Comic # 244
! Starlog Magazine # 39
! Fangoria Magazine # 8
! She is reading Wonder Woman # 272
! Born in 1963
! 1980 She's 17 - working at the convience store

! Character Diamond
! 1: Mediocre - Not Ambitious - Lazy In School
! 2: Nice - Honest
! 3: Happy - Spoiled
! 4: Introvert - Afraid

! ---------------------------------------------------------------------------- !
!       AMY. 09/28/17
! Age: 17

  Object  convenienceStoreAmy "clerk"
    with  name 'amy' 'attendant' 'girl' 'chick' 'teen' 'clerk' 't-shirt',
          describe [;
              rtrue;
          ],
          daemon [;
              ! Ask For Coke
              if (self.askForCoke) {
                  iAskCoke++;
              }
              if (self.dontKillAskForCoke) {
                  self.dontKillAskForCoke = false;
              } else {
                  if (iAskCoke > 1) {
                      iAskCoke = 0;
                      self.askForCoke = false;
                  }
              }

              ! Ask About Empire
              if (self.askAboutEmpire) {
                  iAskEmpire++;
              }
              if (iAskEmpire > 1) {
                  iAskEmpire = 0;
                  self.askAboutEmpire = false;
              }

              ! Ask About Comic
              if (self.askAboutComic) {
                  iAskComic++;
              }
              if (self.dontKillAskAboutComic) {
                  self.dontKillAskAboutComic = false;
              } else {
                  if (iAskComic > 1) {
                      iAskComic = 0;
                      self.askAboutComic = false;
                  }
              }

              ! Ask About X-Men Comic
              if (self.askAboutXMenComic) {
                  iAskXMenComic++;
              }
              if (self.dontKillAskAboutXMenComic) {
                  self.dontKillAskAboutXMenComic = false;
              } else {
                  if (iAskXMenComic > 1) {
                      iAskXMenComic = 0;
                      self.askAboutXMenComic = false;
                  }
              }

              ! Ask About Watch
              if (self.askAboutWatch) {
                  iAskWatch++;
              }
              if (self.dontKillAskAboutWatch) {
                  self.dontKillAskAboutWatch = false;
              } else {
                  if (iAskWatch > 1) {
                      iAskWatch = 0;
                      self.askAboutWatch = false;
                  }
              }

              if (self.lookUp) {
                  ! Returns Amy back to reading the comic
                  iAmyLookUp++;
              }
              if (self.dontKillLookUp) {
                  self.dontKillLookUp = false;
              } else {
                  if (iAmyLookUp >= 2) {
                      self.lookUp = false;
                      iAmyLookUp = 0;
                      "^The clerk turns back to her comic, flipping the page.";
                  }
              }
          ],
          before [ w1;
              AskCreatureFor:
                  if (convenienceStoreKid in convenienceStore) return AmyDealingWithKid();
                  wn = consult_from;
                  w1 = NextWord();
                  switch (w1) {
                      'sealed', 'beef', 'jerky', 'plastic', 'meat', 'stick', 'sticks':
                          if (self.askedForJerky) "~Don't you get it? I can't do that.~";
                          "~I can't just give it away. They'd fire me.~";
                      'name':
                          iAmyConversation++;
                          return AskAmyForName();
                      'beer', 'alcohol', 'booze':
                          iAmyConversation++;
                          "~Sorry. I can't sell you any. You'll have to wait for the owner to get back.~";
                      'cigarette', 'cigarettes', 'cig', 'cigs', 'fag', 'fags', 'smokes':
                          iAmyConversation++;
                          "~I'm not old enough to sell those. You'll have to wait 'til the owner gets back.~";
                      'change', 'quarters', 'quarter':
                          "~Sorry. We don't have any change. The boss said he'd fill the register,
                          but never took care of it.~";
                      'soda', 'pop', 'coke', 'cokes', 'cola':
                          "~Yeah. The cooler is small, so we only have room for beer. No pop. But we do have some candy.~";
                  }
                  return AmyResponse();
              Examine:
                  if (convenienceStoreKid in convenienceStore)
                      "Clutching her comic book like she's going to strangle it, the clerk sits there, talking to the kid.";
                  if (self.lookUp) {
                      self.lookUp = false;
                      "Looking back down at her comic book, this heavyset girl has frizzy hair and wears a
                      t-shirt that says ~Empire Strikes Back.~";
                  } else {
                      "Leafing through a comic book, this heavyset girl has frizzy hair and wears a
                      t-shirt that says ~Empire Strikes Back.~";
                  }
              Kiss:
                  if (convenienceStoreKid in convenienceStore) return AmyDealingWithKid();
                  "~Sorry,~ she says, pushing you back, ~I don't even know you.~";
              Talk:
                  if (convenienceStoreKid in convenienceStore) return AmyDealingWithKid();
                  print "[You can try ";
                  if (self.askAboutMovieTalk) {
                      print "ASK ABOUT BEEF STICKS";
                  } else {
                      print "ASK ABOUT T-SHIRT";
                  }
                  print " or ";
                  if (self.askAboutComicTalk) {
                      print "ASK ABOUT WONDER WOMAN";
                  } else {
                      print "ASK ABOUT COMIC";
                  }
                  ". There are also lots of other things too.]";
              Hello:
                  if (convenienceStoreKid in convenienceStore) return AmyDealingWithKid();
                  iAmyConversation++;
                  if (self.helloFirstTime) "~How are you?~";
                  self.helloFirstTime = true;
                  "~Hi, you look new.~";
              Eat, Taste:
                  "What? Are you a cannibal? I know you're not that hungry.";
              WaveObject:
                  if (convenienceStoreKid in convenienceStore) return AmyDealingWithKid();
                  if (self.lookUp) {
                      self.dontKillLookUp = true;
                      "~I see you. Can I help?~";
                  }
                  self.lookUp = true;
                  "~Hello, yes. How can I help you?~ she asks, looking up from her comic book.";
              Take:
                  "You know she's not an object?";
              Attack, Blow, Burn, Climb, Close, Cut, Dig, Drink, Eat, Empty, Exit, GetOff, JumpOver, Kick, Listen, LookUnder, Open:
                  "You can't do that. She's behind the counter.";
              Push, PushDir, Pull, Read, Remove, Rub, Search, Set, SetTo, SmellNoun, Squeeze, Swing, SwitchOn, SwitchOff, Take, Talk, Taste, Tie, Touch, Transfer, Turn, Unlock, Wave:
                  "You can't do that. She's behind the counter.";
          ],
          life [ w1 w2;
              if (convenienceStoreKid in convenienceStore) return AmyDealingWithKid();
              Answer:
                  switch(noun) {
                      t_hi: <<Hello self>>;
                      t_yes: return AnswerYesAmy();
                      t_no: return AnswerNoAmy();
                      t_good: "~Glad to hear it.~";
                      t_bad: "~Maybe tomorrow will be better.~";
                      t_sorry: "~Think nothing of it.~";
                      t_thanks: "~I hope it helps.~";
                      default: return (AmyResponse());
                  }
              Ask:
                  iAmyConversation++;

                  wn = consult_from;
                  w1 = NextWord();
                  w2 = NextWord();
                  if (w1 == 'past' ) {
                      if (w2 == 'dated' ) {
                          return AmyPastDated();
                      }
                  }
                  if (w1 == 'high' ) {
                      if (w2 == 'score' ) {
                          return AskAmyHighScore();
                      }
                  }
                  switch (w1) {
                      'floor':
                          "~It's a little dirty, but I can't leave the register right now.~";
                      'halloween', 'samhain':
                          "~Halloween is fun. There is always candy around the house, and I love seeing the kids in their different costumes.~";
                      'bowling', 'alley':
                          "~I love going over there to play the arcade machine. I do it whenever I have quarters,
                          and I've gotten my name on the high score.~";
                      'asteroids', 'arcade', 'machine':
                          "~Asteroids is a blast. And I hate to say it, but I'm pretty good at that game. I hold all the high scores on that machine.~";
                      'score':
                          return AskAmyHighScore();
                      'empire':
                          if (self.askAboutESB) {
                              if (self.sayNoAboutEmpire) "~Too bad we don't agree on the ending. I'm sure Luke is going to join Vader by the end of it, but no one wants to hear it.~";
                              if (self.sayYesAboutEmpire) "~Glad we agree about it. I'm tired of fighting with my family.~";
                              "~You might not feel one way or the other about it, but I loved it.~";
                          }
                          self.askAboutESB = true;
                          self.askAboutEmpire = true;
                          print "~Empire Strikes Back, it was amazing";
                          if (self.lookUp) {
                              print ". ";
                          } else {
                              self.lookUp = true;
                              print ",~ she says looking up, ~";
                          }
                          "I've seen it more times than I've seen Star Wars.
                          And that ending. Wow! Darth Vader is Luke's Father? Can you believe it?~";
                      'shirt', 't-shirt', 'movie':
                          self.askAboutMovieTalk = true;
                          if (self.askAboutESB) {
                              if (self.sayNoAboutEmpire) "~Too bad we don't agree on the ending. I'm sure Luke's going to go evil by the end of it, but no one wants to hear it.~";
                              if (self.sayYesAboutEmpire) "~Glad we agree about it. I'm tired of fighting with my family.~";
                              "~You might not feel one way or the other about it, but I loved it.~";
                          }
                          self.askAboutESB = true;
                          self.askAboutEmpire = true;
                          "~What? Empire? It's amazing. I've seen it more times than I've seen Star Wars. And that ending. Wow! Darth Vader is Luke's Father? Can you believe it?~";
                      'vader':
                          if (self.askAboutESB) {
                              if (self.sayNoAboutEmpire) "~You watch. You might not think Vader is his father, but Luke is going to join him in the end. I'm sure of it - Luke's weak. Yoda told him not to go.~";
                              if (self.sayYesAboutEmpire) "~Yoda told Luke not to go, and I'm sure he will decide to join Vader. It will be a scary time for the Rebellion.~";
                              "~Vader's the bad guy, that's for sure, but I think Luke is going to join up with him. He's weak. Yoda told him not to go.~";
                          }
                          self.askAboutESB = true;
                          self.askAboutEmpire = true;
                          "~Wow! Darth Vader! What a monster. And can you believe it? He's Luke's Father!~";
                      'star':
                          "~Star Wars is great. I saw it six times, and a lot of my friends saw it more than once. But I think Empire is better.~";
                      'luke', 'skywalker':
                          "~Luke's a pushover. He's weak and is going to join Vader. Yoda warned him, but he still left.~";
                      'yoda':
                          "~Isn't Yoda cool? Plus wise and all knowing. I wonder why he's been on Dagobah all this time.~";
                      'brother':
                          "~Yeah. I got a younger brother. We never see eye to eye. He's always on the other side of things.~";
                      'family':
                          "~You know how it is. They don't see it my way most of the time. I want to
                          be a writer, but none of them think I can do it. I don't know. I have my
                          doubts on top of it.~";
                      'writing':
                          "~I started reading when I was young and books could always take me to places I
                          would've never seen. I want to do that. Create new places and stories for people
                          to explore.~";
                      'sealed', 'beef', 'jerky', 'plastic', 'meat', 'stick', 'sticks', 'pack', 'packs':
                          "~Yeah. A lot of people see it up here at the register and buy it.
                          It sells itself.~";
                      'beer', 'alcohol', 'booze':
                          if (self.lookUp) {
                              "~Sorry. I can't sell you any. You'll have to wait for the owner to get back.~";
                          } else {
                              self.lookUp = true;
                              "~I actually can't sell you any beer,~ she says looking up from the comic, ~you'll have to wait for the owner to get back.~";
                          }
                      'city', 'town', 'sunnybrook':
                          "~Lived here all my life. 17 years of it. I love this place.~";
                      'coin':
                          "~You know. Coin, cash. Currency to pay with.~";
                      'dollar':
                          if (dollarBill.gaveAmyDollar) "~What about it? I'm not giving it back.~";
                          if (self.askAboutComic) self.dontKillAskAboutComic = true;
                          self.askAboutComic = true;
                          self.saidNoChange = false;
                          dollarBill.showToAmy = true;
                          if (self.askAboutDollar) "~Like I said, we don't have any change. So how about I sell you the Conan Comic and a candy bar?~";
                          self.askAboutDollar = true;
                          "~So, we don't have any change. How about I sell you the Conan Comic and a candy bar?~";
                      'comic', 'comics', 'book', 'books':
                          self.askAboutComicTalk = true;
                          "~We got some new ones at the beginning of the month. Wonder Woman is my favorite, rereading it right now. But I had to put the past-dated ones in the back.~";
                      'dated', 'past-dated':
                          return AmyPastDated();
                      'friend':
                          "~What? The owner's friend? I don't know him that well. I just see him when he picks up the comics. Why does he get to have them?~";
                      'collection':
                          "~I started almost four years ago. You should see the pile I have. One day I'm going to sell all the extras, but keep a copy of each for myself.~";
                      'spiderman':
                          "~Better comic than X-Men. Why the boss won't sell them, I'll never know. I keep telling him that he'd make more money. He just tells me to shut up.~";
                      'conan', '115':
                          if (dollarBill.gaveAmyDollar)
                              "~There's no way it's better than Wonder Woman, but I hope you like it.~";
                          "~It's the 10th anniversary for that comic. Special edition and a quarter more.~";
                      'wonder', 'woman', 'reading', '272':
                          if (self.askAboutWW)
                              "~I started collecting the series recently. Buying more than one each time a new issue comes out. They're going to be worth a fortune.~";
                          self.askAboutWW = true;
                          print "~I've been reading the series for years";
                          if (self.lookUp) {
                              print ". ";
                          } else {
                              self.lookUp = true;
                              print ",~ she says looking up for a minute. ~";
                          }
                          "And this is a great story where Angle Man attacks the base Diana Prince is stationed at.
                          He pulls her into another dimension.
                          I can't wait to see what happens in the next issue. It looks like she's trapped.~";
                      'rereading':
                          if (self.askAboutWW)
                              "~I can't help myself. This is a great issue. I really do enjoy the story.~";
                          self.askAboutWW = true;
                          print "~I can't help myself. This is a great issue";
                          if (self.lookUp) {
                              print ". ";
                          } else {
                              self.lookUp = true;
                              print ",~ she says looking up for a minute. ~";
                          }
                          "Angle Man attacks the base Diana Prince is stationed at.
                          He pulls her into another dimension.
                          I can't wait to see what happens in the next issue. It looks like she's trapped.~";
                      'story', 'issue':
                          if (self.askAboutWW)
                              "~Well, there's not much more to it than that. Angle Man shows up at the end. Sabotages the shuttle and transports Wonder Woman. But he'll get his before it's over.~";
                          self.askAboutWW = true;
                          print "~It's really well put together, with a cliff hanger at the end";
                          if (self.lookUp) {
                              print ". ";
                          } else {
                              self.lookUp = true;
                              print ",~ she says looking up for a minute. ~";
                          }
                          "Angle Man attacks the base Diana Prince is stationed at.
                          He pulls her into another dimension. It looks like she's trapped.
                          I can't wait to see what happens in the next issue.~";
                      'trap':
                          "~Oh. Angle Man used his Angler. He pulled a space shuttle into another dimension. He pulled Wonder Woman into it too.~";
                      'dimension':
                          "~The other dimension is at 90 degrees. Wonder Woman's trapped. I think she needs to get the Angler.~";
                      'diana', 'prince':
                          if (self.askAboutDiana) "~I know some people I'd like to use that lasso on.~";
                          self.askAboutDiana = true;
                          "~I wish I grew up on Paradise Island. Surrounded by loving sisters. Not my annoying brother.
                          And to have that lasso? You can make anybody tell the truth.~";
                      'next':
                          "~Oh. I'm sure Wonder Woman will make it out of his trap. But she better not stay in there for more than an issue or two.~";
                      'lasso':
                          "~You mean Wonder Woman's magic lasso? I can think of a few people I'd like to tie up with that.~";
                      'angle', 'man':
                          "~He's a part of the Secret Society of Super-Villains, and he put Wonder Woman is a bind. Pulled her into another dimension. What is she going to do?~";
                      'angler', 'weapon':
                          "~That weapon is too powerful. Angle Man used it two years ago to transport himself from 1978, where he almost died, to 1945. It's not even fair. Now he's pulled Wonder Woman into a 90-degree dimension.~";
                      'space', 'shuttle', 'rocket':
                          "~In the issue, it looked more like a rocket. But they said they were going to take people into space quickly.~";
                      'unknown', 'soldier':
                          "~That's one of the last in a long line of war comics since the 40s. Not my type though.~";
                      'xmen', 'x-men', '138':
                          "~Some interesting superheroes in that one. I even like Storm. But no one is like Diana Prince.~";
                      'bus':
                          "~The bus that runs to Melville? It runs all night if you're looking to head out that way.~";
                      'library':
                          "~I love the library - all those books and so quiet inside.
                          I feel the mysteries of life must be answered in there.~";
                      'the', 'tavern':
                          "~Gee. I can't wait. Only a year left and then I can go in there. Nick works the
                          place. I'd love to have him wait on me.~";
                      'school', 'schooling':
                          "~High school can be a drag. None of the girls like me and I get picked on all
                          the time. Only a year to go, but I'm not sure what to do after I graduate.
                          I'd like to go to college.~";
                      'college':
                          "~I'm hoping college turns out better than high school. If I go. I'm hoping to
                          major in English. But I'm still not sure.~";
                      'post', 'office':
                          "~That post office is old. Older than the town. They say this was a drop-off
                          point for the mail. Back when it was run up cow trails.~";
                      'yard', 'junkyard', 'millers', 'miller', 'miller^s', 'miller?s':
                          "~Yeah. Mr. Miller's a pain, buys his beer from here. Whenever he sees me he's always giving me crap,
                          calling me a slacker. He's just a crabby old man.~";
                      'dog', 'doberman':
                          "~I wouldn't mess with that dog. Mr. Miller has that thing trained to kill.~";
                      'gas', 'station':
                          "~Jerry works over there. Mostly at night. Too bad. I don't get to see him much.
                          He never stops by.~";
                      'pharmacy':
                          "~Mabel won't be back 'til morning. I'm sure if you need something, it can wait 'til then.~";
                      'house', 'abandoned':
                          "~The abandoned one behind the alley? I don't go over there. Some kid was killed during its construction. It's haunted.~";
                      'trailer', 'park':
                          "~I've never been over to the trailer park. Jerry never asked me.~";
                      'cold', 'drink', 'drinks', 'bottle', 'coke', 'cokes', 'cola', 'soda', 'pop':
                          "~Yeah. The cooler is small, so we only have room for beer. No pop. But we do have some candy.~";
                      'dr', 'pepper':
                          "~Oh. I love Dr. Pepper. It's delicious.~";
                      'name':
                          return AskAmyForName();
                      'amy', 'girl', 'chick', 'teen', 'clerk', 'her', 'herself':
                          if (self.askAboutSelf) "~What can I say? Maybe I'll write a book one day.~";
                          self.askAboutSelf = true;
                          "~You know, when I think about it, I'm hoping to write a book someday.
                          But I don't know. Who would read it?~";
                      'owner', 'boss', 'manager':
                          if (self.lookUp) {
                              self.lookUp = false;
                              "~The owner left a while ago now. I'm sure he'll be back any time,~
                              she says fidgeting as she turns back to her comic book.";
                          } else {
                              "~The owner left a while ago now. I'm sure he'll be back any time,~
                              she says fidgeting as she turns a page in her comic.";
                          }
                      'mabel':
                          "~Mabel's prompt. Always leaves by 5 p.m. A real stickler. But I guess you
                          have to be with a job like hers.~";
                      'snack', 'snacks', 'bar', 'bars', 'missing', 'box', 'junk', 'food', 'chocolate', 'candy', 'snickers', 'snicker':
                          return TellAmySnacks();
                      'yukypah', 'heef', 'statue':
                          "~I think everybody knows about that statue. They teach about him in grade school.
                          They say he laid the first granite blocks himself. If you believe them.~";
                      'convenience', 'drug', 'store':
                          "~I've worked here for a year. Customers are friendly. I like it.~";
                      'work', 'job', 'shop', 'place':
                          "~When it's slow like this it's easy for me to get in some reading.~";
                      'scientist':
                          "~I haven't seen anybody like that stop by. Sorry.~";
                      'sam':
                          print "~I don't remember anybody like that coming in here.";
                          return AskMultiAboutSam();
                      'judy':
                          "~If she doesn't come in here I don't know her.~";
                      'mark', 'tom':
                          "~Never heard of him. Does he live around here?~";
                      'time', 'machine', 'note', 'notes': "You better keep that information to yourself.";
                      'covid', 'bug', 'corona', 'coronavirus', 'virus': "You should keep that information to yourself.";
                      'bum', 'ed', 'eddie':
                          if (smallParkEddie.amyTold) "~Stop. I don't want to talk about him anymore.~";
                          smallParkEddie.amyTold = true;
                          "~What? That creepo? Yeah he's strange. I see him watching me from the park.
                          I started going 'round South Street just to stay clear of him.~";
                      'melville', 'melvill':
                          "~I've never been over there. But I hear it's not the cleanest place.~";
                      'current', 'date', 'year':
                          "~The '80s are going to be great. Even better than the '70s I think.
                          Look at Empire, George Lucas couldn't do better.~";
                      'doorman':
                          "~Might as well stay away from that guy. You'll get nowhere with him.~";
                      'complex', 'high-rise', 'highrise', 'highland', 'towers', 'apartment', 'apartments':
                          "~It's a pretty nice looking structure. Wish I could live there one day.~";
                      'jerry', 'attendant':
                          "~Jerry's my age. We were born the same year. Cute guy.
                          He works over at the station. At night mostly. So I never see him over here.~";
                      'harry', 'old', 'guy':
                          "~Oh, the old guy. Yeah. Harry. He comes in here now and then to buy lottery tickets.
                          Stinks of booze most the time.~";
                      'phil', 'phill':
                          "~What? the bartender over at the alley? I don't ever see him in here.~";
                      'bob':
                          "~The owner of the alley? I see him when he comes in here to talk with the boss, but he doesn't even notice me.~";
                      'pops':
                          if (self.askAboutPops) "~Yeah. I don't really like to talk about that.~";
                          self.askAboutPops = true;
                          "~Pops was this old hippy dude around here. He was drafted into Vietnam and didn't like it.
                          Overdosed a few years back.~";
                      'nancy', 'punk', 'fox':
                          "~The girl that works over at the bowling alley. All the guys think she's a fox.~";
                      'nick':
                          "~The cute guy that works over at The Tavern? Wish I could drink. I'd go over there
                          to watch him play. I hear he sits in with a few of the bands.~";
                      'art', 'gallery':
                          "~The curator over there's a little strange. Comes in here every night. Looks me
                          up and down. Then leaves. Almost a ritual. I want to tell her off. But I know I
                          should mind my manners.~";
                      'sarah', 'curator', 'hippie':
                          "~Yeah, the curator is a hippie for sure. Real throwback from the '60s. Comes in here every
                          night too. Never buys anything. She's an odd one.~";
                      'madame', 'sorra', 'gypsy', 'fortune-teller', 'fortune', 'teller':
                          "~That old fortune-teller? She never comes in here. I don't think she ever leaves her shop.~";
                      'cigarette', 'cigarettes', 'cig', 'cigs', 'fag', 'fags', 'smokes':
                          "~I can't sell you those. You'll have to wait 'til the owner gets back.~";
                      'change', 'quarters', 'quarter':
                          "~Sorry. We're out of change right now. The boss said he'd fill the register
                          but never took care of it.~";
                      'kids':
                          "~Yeah, the kids around town love to come in here and read the comics. They never buy them,
                          and it upsets the owner, but I don't care. Mel is the only real one I have problems with.~";
                      'kid', 'mel':
                          "~Yeah, Mel. That kid is a piece of work. His dad knows the owner, so he thinks he can have what he wants - spoiled if you ask me.~";
                      'plug', 'spark', 'sparkplug', 'fuse':
                          "~You're looking for a spark plug? The only place I'd look for one is down at the
                          gas station. Jerry is a great guy. I'm sure he'll help you.~";
                      'shard':
                          "~I don't know about a shard, but that hippie over at the art gallery always
                          has some crystals.~";
                      'crystal', 'crystals':
                          "~That hippie over at the art gallery used to carry some necklaces that were crystal. You might want to look over there.~";
                      'vacuum', 'tube', 'tubes':
                          "~A vacuum tube? Not sure where to find one of those. Have you looked in Miller's yard? He has all sorts of junk. Just watch out for that dog.~";
                      'me', 'self', 'yourself':
                          "~You haven't been in here before tonight.~";
                      'cooler':
                          "~The boss has been talking about getting a bigger one. He thinks he's going to be able to sell more,
                          even though he has room for plenty of beer.~";
                      'stan', 'lee':
                          "~Stan's the man when it comes to comics. I bet he's sitting on a mountain of cash. Spiderman has to be his best.~";
                      'him', 'himself', 'her', 'herself', 'them':
                          "At the moment, even the simplest questions are confusing.";
                      default:
                          return (AmyResponse());
                  }
              Tell:
                  wn = consult_from;
                  w1 = NextWord();
                  switch(w1) {
                      'hi', 'hello', 'hola', 'greetings':
                          <<Hello self>>;
                      'snack', 'snacks', 'bars', 'missing', 'box', 'bar', 'junk', 'food', 'chocolate', 'candy', 'snickers', 'snicker':
                          iAmyConversation++;
                          return TellAmySnacks();
                      'yes', 'please', 'ok':
                          return AnswerYesAmy();
                      'no':
                          return AnswerNoAmy();
                      'good':
                          "~Glad to hear it.~";
                      'bad':
                          "~Maybe tomorrow will be better.~";
                      'sorry':
                          "~Think nothing of it.~";
                      'bum', 'ed', 'eddie':
                          if (smallParkEddie.amyTold) "~I don't want to hear about him. Like I said, he's a creep.~";
                          "~I don't want to hear about him. He's a creep.~";
                      'time', 'machine', 'note', 'notes', 'house', 'abandoned', 'date', 'year':
                          "You better keep that information to yourself.";
                      'covid', 'bug', 'corona', 'coronavirus', 'virus': "You should keep that information to yourself.";
                      'him', 'himself', 'her', 'herself', 'them':
                          "At the moment, even the simplest statements are confusing.";
                      default:
                          return (AmyResponse());
                  }
          ],
          orders [;
              if (convenienceStoreKid in convenienceStore) return AmyDealingWithKid();
              Hello:
                  <<Hello self>>;
              Give:
                  if (noun == convenienceStoreJerky) {
                      if (self.askedForJerky) "~Don't you get it, I can't do that.~";
                      self.askedForJerky = true;
                      "~You know, you look nice and all, and I'd like to, but they'd fire me.~";
                  }
              Strong: "The clerk ignores you.";
          ],
          amyScored false,
          amyReturn false,
          seensnacks false,
          askedForJerky false,
          askForCoke false,
          dontKillAskForCoke false,
          askAboutMovieTalk false,
          nameFirstTime false,
          nameSecondTime false,
          helloFirstTime false,
          askAboutSelf false,
          askAboutEmpire false,
          askAboutESB false,
          sayYesAboutEmpire false,
          sayNoAboutEmpire false,
          lookUp false,
          askAboutComic false,
          dontKillAskAboutComic false,
          askAboutPops false,
          askAboutDiana false,
          askAboutComicTalk false,
          saidNoChange true,
          askAboutDollar false,
          askAboutXMenComic false,
          dontKillAskAboutXMenComic false,
          askAboutWW false,
          askAboutWatch false,
          dontKillAskAboutWatch false,
          dontKillLookUp false,
    has   animate female concealed scenery;

  [ AmyResponse;
        if (iAmyConversation > 5) {
            iAmyConversation = 0;
            "~I'm sorry. I got a lot of things to do. Are you going to keep going on all night? You know, 'cause,
            I thought you were gonna buy something.~";
        }
        if (iAmyConversation > 3) "~Sorry. I just don't know about that.~";
        "~Not sure about that. Maybe I can help you with something else.~";
  ];

  [ AmyDealingWithKid;
        "~I'm sorry. Mel came first. Let me deal with him, please.~";
  ];

  [ AskAmyForName;
        SelfPlayer.knowAmy = true;
        if (convenienceStoreAmy.nameSecondTime) "~Okay. Cut it out.~";
        if (convenienceStoreAmy.nameFirstTime) {
            convenienceStoreAmy.nameSecondTime = true;
            "~Are we playing a game or something? I'm Amy.~";
        }
        convenienceStoreAmy.nameFirstTime = true;
        convenienceStoreAmy.amyScored = true;
        iPeople++;
        print "~I'm Amy";
        if (convenienceStoreAmy.helloFirstTime) ".~";
        ". Haven't seen you before.~";
  ];

  [ AnswerYesAmy;
        if (convenienceStoreAmy.askAboutEmpire) {
            convenienceStoreAmy.sayYesAboutEmpire = true;
            "~I know. Right? I keep telling my brother, but he thinks Vader's lying.~";
        }
        if (convenienceStoreAmy.askAboutComic) {
            if (dollarBill in player || dollarBill in clothes) return GiveDollarBill();
            "~You say you want to buy it, but you don't have any coin.~";
        }
        if (convenienceStoreAmy.askAboutXMenComic) {
            if (dollarBill in player) "~That's not Stan Lee's best work. I wish we had Spiderman in, but the boss won't splurge. Don't waste your money.~";
            "~You say you want to buy it, but you don't have any coin.~";
        }
        if (convenienceStoreAmy.askAboutWatch) {
            "~That's strange. I don't know why anybody would do that.~";
        }
        "~Nice to see your positive side.~";
  ];

  [ AnswerNoAmy;
        if (convenienceStoreAmy.askAboutEmpire) {
            convenienceStoreAmy.sayNoAboutEmpire = true;
            "~You sound just like my brother. He thinks Vader's lying too. Wish someone would see it my way.~";
        }
        if (convenienceStoreAmy.askAboutComic) "~I didn't think so.~";
        "~Don't be negative, life should be a joy. That's what Pops always said.~";
  ];

  [ TellAmySnacks;
        if (convenienceStoreAmy.seensnacks) {
            if (convenienceStoreAmy.amyReturn) "~I already took care of that. Thanks for noticing,~ she says with an impish smile.";
            remove self;
            "~What? The Snickers are missing. Thanks. My boss would kill me. I'll be right back.~
            ^^Nodding to you, she puts the comic down on the counter and goes in the back.";
        }
        "~We have all types. Take a look around.~";
  ];

  [ AmyPastDated;
        "~The past-dated ones are still good, but we don't sell them. The owner has a friend
        that picks them up. He gets a good deal.~";
  ];

  [ AskAmyHighScore;
        "~Yeah. All ten on that machine say AMB. Twenty years from now, I hope no one tops it. Be nice to see it still up there. I worked hard for that.~";
  ];
