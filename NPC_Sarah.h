! To get Sarah to break the crystal, the player has to take the incense
! the player can't leave with the incense so they have to drop it (game will force)   '
! Sarah will go over and pick them up, bumping in to cat, breaking the crystal
! Age: 32
!
! Sarah secretly smokes, there needs to be cigarette butts in the alley, And
! The player needs to be able to ask about them
!
! 1948: - Born
! 1967: 19 - Minoring in Art at Berkley
! 1972: 24 - Graduated Berkley with an Major in Art
! 1972 - 1976: Lives on a commune

! Character Diamond
! 1: Has Secret - Regrets Smoking
! 2: Mystical
! 3: Greedy
! 4: Ambitious - Wants Her Business To Succed - Doesn't want to let her parents down

! ---------------------------------------------------------------------------- !
!       SARAH. 01/17/18
!

  Object  -> artGallerySarah "curator"
    with  name 'sarah' 'attendant' 'curator' 'woman' 'middle-aged' 'lady' 'skirt' 'dress' 'white' 'hair' 'hippie',
          describe [;
              rtrue;
          ],
          daemon [;
              ! Used to listen to for staying in the city / response Yes/No
              if (self.cityStay) {
                  iAskStay++;
              }
              if (self.dontKillCityStay) {
                  self.dontKillCityStay = false;
              } else {
                  if (iAskStay > 1) {
                      iAskStay = 0;
                      self.cityStay = false;
                  }
              }

              ! Used to listen to for leaving in the city / response Yes/No
              if (self.cityGo) {
                  iAskGo++;
              }
              if (self.dontKillCityGo) {
                  self.dontKillCityGo = false;
              } else {
                  if (iAskGo > 1) {
                      iAskGo = 0;
                      self.cityGo = false;
                  }
              }

              ! Used when the currator says to Please Use The Front Door
              if (self.useDoor) {
                  iAskDoor++;
              }
              if (self.dontKillUseDoor) {
                  self.dontKillUseDoor = false;
              } else {
                  if (iAskDoor > 1) {
                      iAskDoor = 0;
                      self.useDoor = false;
                  }
              }

              ! Used to move currator back to the counter
              if (self.moveBlock) {
                  iAskMoveBlock++;
              }
              if (iAskMoveBlock > 1) {
                  iAskMoveBlock = 0;
                  self.moveBlock = false;
                  print "^The curator moves back to the counter, looking at some paperwork";
                  if (incense in artGalleryCounter) " and pushing the incense out of the way.";
                  ".";
              }
          ],
          before [ w1;
              AskCreatureFor:
                  if (incense in SelfPlayer) "~I'm not looking for a conversation. Hand back the incense.~";
                  if (self.seenCatBroken || self.seenBallBroken) "~I don't care about what you have to say. Don't come in here again. Skedaddle.~";
                  wn = consult_from;
                  w1 = NextWord();
                  switch (w1) {
                      'name':
                          return AskForNameSarah();
                      'statue', 'ball', 'crystal':
                          "~Do you have any idea how much that costs? I really don't think you can afford it.~";
                      'change', 'quarters', 'quarter':
                          "~I don't deal in small change. Sorry.~";
                  }
                  return SarahResponse();
              Examine:
                  print "She's wearing a loose, open flowing, white dress with long hair past her shoulders";
                  if (incense in SelfPlayer) ". She's right on top of you, and a little upset.";
                  if (self.seenCatBroken || self.seenBallBroken) ". Standing by the counter, she taps her foot impatiently.";
                  if (self.tradedCat) ". You swear that there's a glow about her.";
                  if (self.moveBlock) ". Standing between you and the cat, she looks crossed.";
                  ". Trying to look busy, she stands against the back wall next to a counter.";
              Search, Climb:
                  "I don't think she would care for that.";
              SmellNoun:
                  "You'd look strange smelling her.";
              Kiss:
                  if (incense in SelfPlayer) "~I'm not looking for peace and love. Hand back the incense.~";
                  if (self.seenCatBroken || self.seenBallBroken) "~I'm not looking to be with someone like you. You're a mess. Why don't you leave?~";
                  "~You know I'd like to. Peace and love and all that,~ she says, pushing you back,
                  ~but anybody could walk in.~";
              Rub, Touch, Pet:
                  if (incense in SelfPlayer) "~Look. Don't touch me. I want the incense.~";
                  if (self.seenCatBroken || self.seenBallBroken) "~Don't touch me. You're a mess. Why don't you leave?~";
                  "~Don't touch me.~";
              Talk:
                  print "[You can try ";
                  if (self.askAboutCity && self.playerKnowsSorra) {
                      print "ASK ABOUT FORTUNE TELLER";
                  } else {
                      print "ASK ABOUT CITY";
                  }
                  print " or ";
                  if (self.askAboutGallery) {
                      if (self.askStatue) {
                          print "ASK ABOUT SCULPTOR";
                      } else {
                          print "ASK ABOUT STATUE";
                      }
                  } else {
                      print "ASK ABOUT GALLERY";
                  }
                  ". There are also lots of other things too.]";
              Hello:
                  if (incense in SelfPlayer) "~I'm not looking for a conversation. Hand back the incense.~";
                  if (self.seenCatBroken || self.seenBallBroken) "~I don't want to be your friend. Why don't you skedaddle.~";
                  print "~Hello, glad to help you";
                  if (SelfPlayer.eveningTime || SelfPlayer.nightTime || livingRoomWindow.settingSun) " this evening.~";
                  ".~";
              Eat, Taste:
                  "What? Are you a cannibal? I know you're not that hungry.";
              WaveObject:
                  if (incense in SelfPlayer) "~Yeah. I see you. Now hand back the incense.~";
                  if (self.seenCatBroken || self.seenBallBroken) "~Yeah. I see you. I wish I didn't. Just leave.~";
                  "~You know, we're the only two in this room. I'm here if you need me.~";
              Take:
                  "You know she's not an object?";
              Push, Pull:
                  "~What are you doing? Don't touch me.~";
          ],
          life [ w1 w2;
              Answer:
                  if (incense in SelfPlayer) "~I'm not looking for a conversation. Hand back the incense.~";
                  if (self.seenCatBroken || self.seenBallBroken) "~I don't care about what you have to say. I don't want to see you in here again. Leave.~";
                  switch(noun) {
                      t_goodbye: return (SarahGoodBye());
                      t_hi: <<Hello self>>;
                      t_yes: return AnswerYesSarah();
                      t_no: return AnswerNoSarah();
                      t_good: "~Glad to hear it.~";
                      t_bad: "~Maybe tomorrow will be better.~";
                      t_sorry: "~I'm sure it's nothing.~";
                      t_thanks:
                          if (self.tradedCat) "~No. Thank you. This piece will help me out.~";
                          "~Why? I'm not giving this crystal away.~";
                      default:
                          return SarahResponse();
                  }
              Ask:
                  if (incense in SelfPlayer) "~I'm not looking for a conversation. Hand back the incense.~";
                  if (self.seenCatBroken || self.seenBallBroken) "~What? Now you want to have a conversation like we're friends. Get out of here. You're a mess.~";
                  wn = consult_from;
                  w1 = NextWord();
                  w2 = NextWord();
                  if (w1 == 'crystal' ) {
                      if (w2 == 'ball' ) {
                          return (SarahAskBall());
                      }
                  }
                  if (w2 == 'butt' || w2 == 'butts') {
                      return SarahAskAboutButts();
                  }
                  switch (w1) {
                      'halloween', 'samhain', 'harvest':
                          "~It's the harvest, you know. They used to have huge bonfires this time of year, Wicker Men set ablaze, to honor the gods for their gifts.~";
                      'wicker', 'bonfires':
                          "~Some say they burnt people as sacrifices. But I don't think so. The druids wouldn't be that cruel.~";
                      'gods':
                          "~I'm sorry. There's too many to name them all.~";
                      'gift', 'gifts':
                          "~The gods provided the harvest. The druids were just paying respect.~";
                      'druids':
                          "~They're the ones that followed the seasons and learned about the solstices. After the fall equinox, the harvest always comes a month later.~";
                      'alley':
                          if (self.askedAboutButts) "~Smoking out there just works. It's quiet, plus it keeps the smell out. But I still burn the Nag Champa.~";
                          "~What do you mean? It would be best if you minded your own business. I'm not doing anything out there.~";
                      'dumpster':
                          if (self.askedAboutButts) "~Yeah, there are a lot of cigarettes around the dumpster. I'm too lazy to pick them up.~";
                          "~So. It's a little messy out there. It's not my fault.~";
                      'door':
                          "~I painted the tree of life there when I first moved in. May Gia bless us.~";
                      'tree':
                          "~Isn't it beautiful? It's roots go deep, showing I plan to stay.~";
                      'bowling':
                          "~That place is a little on the rough side. I don't hate the people. I love
                          everybody, don't get me wrong. But I don't relate to most of them either.~";
                      'butt', 'butts', 'filter', 'filters':
                          return SarahAskAboutButts();
                      'cigarette', 'cigarettes', 'cig', 'cigs', 'fag', 'fags', 'smokes':
                          if (self.askedAboutButts) {
                              if (self.askedAboutCigs) "~Yeah, yeah. I'm a bit of a hypocrite. It's not the worst thing I could do.~";
                              self.askedAboutCigs = true;
                              "~Okay. So I'm a bit of a hypocrite. I've been smoking since I came to this town. I didn't do it when I was in the commune. This city has just gotten to me.~";
                          }
                          "~Cigarettes? You know you shouldn't smoke. They're bad for you.~";
                      'house', 'abandoned':
                          self.askAboutHouse = false;
                          "~Oh, you must mean the place that Eddie sleeps in. I feel sorry for him, but there's not much I can do.~";
                      'city', 'town', 'sunnybrook':
                          if (self.answeredNoCity) {
                              if (self.cityGo) self.dontKillCityGo = true;
                              self.cityGo = true;
                              "~I don't know what I'm going to do. Maybe I should leave like you said.~";
                          }
                          if (self.answeredYesCity) {
                              "~I'd like to settle here.~";
                          }
                          if (self.cityStay) self.dontKillCityStay = true;
                          self.cityStay = true;
                          self.askAboutCity = true;
                          "~It's small and backward, but it has its charm. It's grown on me. I plan to settle here if I can.~";
                      'current', 'date', 'year':
                          "~Right now, times are a-changing. I lived through the 60s, and they were a time of hope,
                          but the 80s feel like it's all going to be about self-indulgence.~";
                      'time', 'machine', 'note', 'notes': "You better keep that information to yourself.";
                      'covid', 'bug', 'corona', 'coronavirus', 'virus': "You should keep that information to yourself.";
                      'name':
                          return AskForNameSarah();
                      'yukypah', 'heef':
                          "~You know. I caught Eddie relieving himself on that statue once. I really cursed him out.
                          I don't think he'll be doing that again.~";
                      'price', 'cost':
                          "~If you have to ask. I doubt you can afford it.~";
                      'madame', 'sorra', 'gypsy', 'fortune-teller', 'fortune', 'teller':
                          if (self.tradedCat)
                              "~Thanks for the trade. I'm sure Sorra wouldn't mind.
                              She may not have liked me, but I'll see that this crystal ends up in
                              the right home.~";
                          if (self.seenBallBroken) "~She made the wrong choice giving you her crystal ball.~";
                          if (self.tellAboutSorra)
                              "~Why would she walk away from that life? I thought she was making good money.~";
                          if (self.askAboutSorra)
                              "~Not sure about her. Why would she give you that crystal ball? She always had something against me.~";
                          if (crystalBall in player) {
                              self.askAboutSorra = true;
                              "Seeing the crystal in your hand, she says, ~How did you get Sorra's crystal ball?
                              I've been trying for years. She wouldn't hand it over. Why did she give it to you?~";
                          }
                          "~That old fortune-teller? Yeah. She's a stubborn one. I've been nothing but kind to her over the years.
                          But what does she want for the crystal ball? It would be a beautiful piece for this gallery.~";
                      'ball':
                          return (SarahAskBall());
                      'cat', 'statue', 'sculpture', 'crystal', 'crystals', 'statues':
                          if (self.seenCatBroken) "~I can't believe you'd do something like that. Just get out of here. You have no respect.~";
                          if (self.tradedCat) "~I hope you like it. A close friend of mine made it.~";
                          if (self.askStatue) "~I know it's hard to believe, but we have some very talented people that live in this town. The sculptor makes some excellent stuff.~";
                          self.askStatue = true;
                          "~It's a beautiful statue. Isn't it? A local sculptor makes them. I used to sell necklaces, but I had to move on to something sturdier.~";
                      'shard':
                          if (self.seenCatBroken) "~I can't believe you'd do something like that. Just get out of here. You have no respect.~";
                          if (self.seenBallBroken) "~Sorra made the wrong choice in giving you her crystal ball.~";
                          if (crystalShard in player) "~Keep that to yourself. Bad juju friend.~";
                          "~I use to deal in smaller crystals that were used in necklaces, but I never made any
                          profit. I found this sculptor and things have started to work out.~";
                      'sculptor':
                          if (artGalleryStatue in artGalleryPedestal)
                              "~He's become a friend of mine and is a great artist. Somehow he puts
                              together these fantastic works. That cat is solid with no cut lines.
                              It's clean and clear, perfectly aligned, crystal.~";
                          "~He'll be happy. I'll have to order another statue from him.~";
                      'friend', 'artist':
                          "~The sculptor? He's just a friend. Nothing funny is going on there.~";
                      'gallery', 'work', 'job', 'shop', 'place':
                          self.askAboutGallery = true;
                          print "~I've been doing this for the past four years. I had to take out a loan,
                          my parents put up the collateral, but I've always had a love for art. ";
                          if (self.knowAboutCollege) print "I majored in it in college. ";
                          "I even help out this local sculptor. We have a deal that gives him exposure.~";
                      'commune':
                          "~I lived on a commune. I found the place while going to Berkeley.
                          Interesting bunch of people to live with, but after four years, things
                          started to break up. I had to find my own way.~";
                      'berkeley':
                          if (self.askedAboutBerkeley) "~As I said, that's another story. I don't have time to go into it.~";
                          self.askedAboutBerkeley = true;
                          "~Berkeley was amazing. I was an undergrad in 1967. I saw it all.
                          It's a miracle that I even graduated. That's another story.~";
                      'incense', 'nag', 'champa', 'gonesh', 'pack', 'smell', 'ordor', 'stick':
                          if (incense in artGalleryCounter)
                              "~Do you like it? It's Nag Champa. It's a lovely smell. It comes from India.
                              I discovered it when I lived at the commune. And please leave the pack alone.
                              It's not for sale.~";
                          "~Do you like the smell? It's Nag Champa. I usually keep a pack around, but I torched the last stick.~";
                      'library':
                          "~The library's the only other place in this town that tries to cultivate peace.
                          Like me, they keep it quiet in there. But I'm the one that likes to burn the incense.~";
                      'art':
                          "~What can I say? I'm in love with painting and all the colors artists
                          bring out. Or sculptors with their creations that have a life of their own.
                          It's amazing.~";
                      'amy', 'clerk', 'girl', 'convenience', 'drug', 'store':
                          "~I go over to the drug store almost every night. Chocolate is my weakness. But when I see Amy,
                          something reminds me of how bad the stuff is for you. I don't need to put on weight like that.~";
                      'bum', 'ed', 'eddie':
                          if (chocolateBar.giveToSarah)
                              "~Now, I feel bad. I try to help Eddie out. He would've loved that
                              snack. A lot more than me. I'm just putting on the pounds.~";
                          if (self.askSecondHouse) "~Eddie? Yeah. He's a lost soul.~";
                          print "~Eddie? The guy in the park? He's a lost soul. I've been trying to get him to quit drinking for what seems like years. ";
                          if (self.askAboutHouse) {
                              self.askAboutHouse = false;
                              "I think he sleeps in the abandoned house. It's not comfortable, but it keeps him dry.~";
                          }
                          self.askSecondHouse = true;
                          "I doubt he'll ever stop. So I try to help him out. Give him a little change. What can I do?~";
                      'school', 'schooling', 'college', 'undergrad':
                          self.knowAboutCollege = false;
                          "~I loved school. I graduated from Berkeley. Majored in art. But instead of
                          using the degree to teach I ended up opening this gallery.~";
                      'gas', 'station':
                          "~I don't get over there often. I don't even own a car. I walk to work every day.
                          It's a healthy way to live and good for the environment.~";
                      'post', 'office':
                          "~We get junk mail from the post office all the time. I hate going through it.
                          And what a waste of paper. All those trees cut down. For what?~";
                      'yard', 'junkyard', 'millers', 'miller', 'miller^s', 'miller?s':
                          "~Mr. Miller's not a kind man and treats his dog just as poorly. I wish there
                          were something I could do about it, but no would listen.~";
                      'dog', 'doberman':
                          "~It's unfair how Mr. Miller treats that dog. He keeps it hungry so that
                          it will attack anybody that shows up. Cruel. If you ask me.~";
                      'doorman':
                          "~I see him now and then. He lives in my sub. Not the
                          friendliest of neighbors no matter how nice you are to him.~";
                      'complex', 'high-rise', 'highrise', 'highland', 'towers', 'apartment', 'apartments':
                          "~Look at those people. They're full of themselves. It's the real problem
                          with the world.~";
                      'harry', 'old', 'guy':
                          "~The grumpy old guy that hangs out at The Tavern? You can try to love
                          someone like that, but it's not going to come back.~";
                      'jerry', 'attendant':
                          "~He seems to be a sweet kid, but I never see him much.~";
                      'nancy', 'punk':
                          "~I've seen her leave the bar late at night with Nick. A real... tramp. I can tell you that.~";
                      'nick', 'bartender':
                          "~I see him now and then. Cute guy. But I don't know about the whole
                          rock and roll thing. I mean. I like The Doors or Jefferson Airplane,
                          but this new stuff is different.~";
                      'phil', 'phill':
                          "~He's older than me. I know that. But I never see him. He can't
                          afford a thing I sell, and I don't get over there.~";
                      'bob':
                          "~Bob never comes around anymore. I saw him in here when I sold necklaces, but he hasn't come back since I switched to statues.~";
                      'sarah', 'curator', 'herself', 'hippie', 'woman', 'her', 'lady':
                          "~I like it here in this small town. I opened my shop a few
                          years back. Got to know the people. It's the customers that keep me going.~";
                      'mabel':
                          "~You know, I feel sorry for her. She's stuck working over at the pharmacy.
                          I guess she could try to relocate to Melville, but that would be hard on
                          anybody.~";
                      'pharmacy':
                          "~I don't get over there much, but Mabel must be an angel. Dealing with sick
                          people like that. How giving.~";
                      'bus':
                          "~The bus will take you to Melville if you're looking to go that way. Never been
                          there myself, but I'm sure the people are nice.~";
                      'melville', 'melvill':
                          "~I rarely see someone from Melville in here. They can't afford my art and they
                          don't appreciate it.~";
                      'the', 'tavern', 'bar':
                          "~The place next door? One of the bartenders likes to blare music all the time.
                          I'd say something if he weren't so cute.~";
                      'change', 'quarters', 'quarter':
                          "~I don't deal in small change. Sorry.~";
                      'plug', 'spark', 'sparkplug', 'fuse':
                          "~A spark plug? I have no idea where you'd find something like that. What about
                          the old junkyard?~";
                      'necklace', 'necklaces':
                          "~I carried crystal necklaces. Beautiful things. But then they started to fall out of
                          their mounts and break. I was losing money. So I had to switch.~";
                      'trailer', 'park':
                          "~People from the trailer park stop by now and then, but I don't have anything
                          they want anymore. They use to come around when I carried these necklaces, but I
                          never made any money. So I found a new line.~";
                      'curse', 'curses', 'hex':
                          "~I'm sure that fortune-teller put a hex on me. My necklaces were fine, until one day
                          they all started to break and people wanted their money back.~";
                      'vacuum', 'tube', 'tubes':
                          "~You got me there. Maybe the bartender next door knows something. He's into all those electronics.~";
                      'scientist', 'mark', 'tom':
                          "~Sorry. I don't know him. I'm sure I can help you with something else.~";
                      'sam':
                          print "~Sorry. I don't know him. I'm sure I can help you with something else.";
                          return AskMultiAboutSam();
                      'judy':
                          "~Sorry. I don't know her. I'm sure I can help you with something else.~";
                      'opportunity':
                          "~Mind your own business.~";
                      'me', 'self', 'yourself':
                          "~I'm sorry. I don't know you, though you look familiar.~";
                      'booze', 'drink', 'flask':
                          "~Have you been talking to Eddie again? I've tried to get him to stop, but he won't listen. Please don't give in to his vice.~";
                      'india':
                          "~India is an amazing place. My guru is from there.~";
                      'guru':
                          "~Oh. I don't like to talk about him, but he's helped me through a lot.~";
                      'chocolate', 'snack', 'candy':
                          if (self.talkedAboutCandy) "~What would you know.~";
                          if (chocolateBar.giveToSarah) {
                              self.talkedAboutCandy = true;
                              "~Why did I eat that? I'm heavy enough as is.~^
                              ^You tell her she looks fine.^
                              ^~What would you know.~";
                          }
                          "~If you have some, you should really give it to Eddie. The poor guy must be hungry all the time.~";
                      'him', 'himself', 'her', 'them':
                          "At the moment, even the simplest questions are confusing.";
                      default:
                          return SarahResponse();
                  }
              Tell:
                  if (incense in SelfPlayer) "~I'm not looking for a conversation. Hand back the incense.~";
                  if (self.seenCatBroken || self.seenBallBroken) "~I don't want to hear what you have to say - breaking something like that. Get out of here.~";
                  wn = consult_from;
                  w1 = NextWord();
                  w2 = NextWord();
                  if (w1 == 'crystal' ) {
                      if (w2 == 'ball' ) {
                          return (SarahTellBall());
                      }
                  }
                  switch(w1) {
                      'goodbye', 'goodby', 'good-bye', 'bye', 'cheerio':
                          return (SarahGoodBye());
                      'hi', 'hello', 'hola', 'greetings':
                          <<Hello self>>;
                      'yes', 'please', 'ok':
                          return AnswerYesSarah();
                      'no':
                          return AnswerNoSarah();
                      'good':
                          "~Glad to hear it.~";
                      'bad':
                          "~Maybe tomorrow will be better.~";
                      'sorry':
                          "~I'm sure it's nothing.~";
                      'cat', 'crystal':
                          if (SelfPlayer.droppedCrystalCat) {
                              if (artGallerySarah.seenCatBroken == false)
                                  "~Damn. I'm thankful for the trade. At least you didn't break the ball. But it's wrong to destroy such a beautiful piece of art.~";
                          }
                          "~What about the crystal cat? It's beautiful, isn't it?~";
                      'time', 'machine', 'note', 'notes', 'house', 'abandoned', 'date', 'year':
                          "You better keep that information to yourself.";
                      'covid', 'bug', 'corona', 'coronavirus', 'virus': "You should keep that information to yourself.";
                      'madame', 'sorra', 'gypsy', 'ball', 'scarf', 'babushka', 'headscarf', 'stole', 'muffler', 'tippet', 'kerchief', 'bandanna', 'fortune-teller', 'fortune', 'teller':
                          return SarahTellBall();
                      'him', 'himself', 'her', 'herself', 'them':
                          "At the moment, even the simplest statements are confusing.";
                      'thanks', 'thank':
                          if (self.tradedCat) "~No. Thank you. This piece will help me out.~";
                          "~Why? I'm not giving this crystal away.~";
                      default:
                          "~Sorry. I wish I could help you.~";
                  }
          ],
          orders [;
              Hello:
                  <<Hello self>>;
              Give:

              Strong: "The curator ignores you.";
              default: if (incense in SelfPlayer) "~Look. Hand back the incense.~";
          ],
          cityGo false,
          dontKillCityGo false,
          cityStay false,
          dontKillCityStay false,
          askStatue false,
          answeredNoCity false,
          answeredYesCity false,
          nameFirstTime false,
          askAboutSorra false,
          tellAboutSorra false,
          seenBallBroken false,
          askAboutCrystal false,
          seenCatBroken false,
          tradedCat false,
          askAboutCity false,
          playerKnowsSorra false,
          askAboutGallery false,
          knowAboutCollege true,
          seenBallInHands false,
          toldAboutBall false,
          askAboutHouse true,
          askSecondHouse false,
          useDoor false,
          dontKillUseDoor false,
          askedAboutButts false,
          askedAboutCigs false,
          askedAboutBerkeley false,
          moveBlock false,
          talkedAboutCandy false,
    has   animate female concealed;

  [ SarahResponse;
        if (incense in SelfPlayer) "~I'm not looking for a conversation. Hand back the incense.~";
        "~Sorry. Can't help you there.~";
  ];

  [ SarahGoodBye;
        if (artGallerySarah.seenBallBroken) "~Good riddance. You're a wreck. Don't come back into my store.~";
        if (artGallerySarah.seenCatBroken) "~Good riddance. You're a wreck. Don't come back into my store.~";
        "~Hopefully, I'll see you again. Remember. We buy and sell rare crystal.~";
  ];

  [ SarahAskBall;
        if (artGallerySarah.seenBallBroken) "~Sorra made the wrong choice in giving you her crystal ball.~";
        if (artGallerySarah.tradedCat) "~I know someone I can sell it to right away. I don't even need to put it up for sale. I'll have to call him tomorrow.~";
        if (crystalBall in player) {
            if (artGallerySarah.tellAboutSorra) "~It's too bad she gave it to you. I could've made a nice profit.~";
            if (artGallerySarah.askAboutCrystal) "~I asked you where you got it from?~";
            artGallerySarah.askAboutCrystal = true;
            "~That's a nice piece of crystal you have there, but it looks like the old fortune-teller's ball. Where did you get it?~";
        }
        if (artGallerySarah.toldAboutBall)
            "~You're a fool. Get out of here before you break something else.~";
        if (artGallerySarah.seenBallInHands)
            "~What happened to the crystal ball you had? I was hoping we could work something out.~";
        "~Madame Sorras' crystal? I'd love to get a hold of that ball. I've tried for years now,
        but that old fortune-teller seems to see through my kindness.~";
  ];

  [ SarahTellBall;
        if (artGallerySarah.tradedCat)
            "~Thanks for the trade. I'm sure Sorra wouldn't mind.
            She may not have liked me, but I'll see that the crystal ends up in
            the right home.~";
        if (madameSorrasMadameSorra in madameSorras)
            "~Yeah. I know all about that old lady,~ the curator says cutting you off,
            ~I've wanted that crystal ball for years, but she won't give it up.~";
        if (crystalBall in player) {
            if (artGallerySarah.tellAboutSorra) "She already knows.";
            artGallerySarah.tellAboutSorra = true;
            "You tell her that you got the crystal ball from the fortune teller.^
            ^~You mean she really gave it up? I've been nice, trying to help her out when I can. But she wouldn't take any cash for it.~^
            ^You tell her that you gave her a scarf, something that was her mother's, and that she was tired of the life and wanted to move on.^
            ^~After all I did for her. That old fortune-teller did it to spite me.~";
        }
        if (artGallerySarah.seenBallBroken) "~She made the wrong choice in giving you her crystal ball.~";
        if (artGallerySarah.seenBallInHands) {
            artGallerySarah.toldAboutBall = true;
            if (crystalShard in player)
                "You show her the crystal shard in your hand, informing her you broken the ball by accident.^
                ^~So you're clumsy and just ruined my opportunity. Great.~";
            "You inform her you broken the ball by accident.^
            ^~So you're clumsy and just ruined my opportunity. Great.~";
        }
        "You inform her that you got the crystal ball from the fortune teller, but dropped it by accident.^
        ^~So you're clumsy and just ruined my opportunity. Great.~";

  ];

  [ SarahAskAboutButts;
        if (artGallerySarah.askedAboutButts) "~It's no biggy. It's not like I'm hurting anybody.~";
        artGallerySarah.askedAboutButts = true;
        "~Okay, it looks like you caught me. Yeah. I smoke in the alley. So what? I picked up the habit when I moved here.~";
  ];

  [ AskForNameSarah;
        SelfPlayer.knowSarah = true;
        if (artGallerySarah.nameFirstTime) "~I told you, Sarah. Is there anything else I can help you with?~";
        artGallerySarah.nameFirstTime = true;
        iPeople++;
        "~Sarah is my name. Glad to help.~";
  ];

  [ AnswerYesSarah;
        if (self.cityStay) {
            if (self.answeredNoCity) "~Change your mind a lot?~";
            if (self.answeredYesCity) "~Okay. I get it.~";
            self.answeredYesCity = true;
            "~Thanks. I've always liked it here.~";
        }
        if (self.cityGo) "~Yeah. I'm thinking about it.~";
        if (self.useDoor) "~Thanks.~";
        if (iRepeat > 3) {
            iRepeat = 0;
            "~I don't think so.~";
        }
        iRepeat++;
        "~Was there a question in there?~";
  ];

  [ AnswerNoSarah;
        if (self.cityStay) {
            if (self.answeredYesCity) "~Change your mind a lot?~";
            if (self.answeredNoCity) "~I'll have to think about that.~";
            self.answeredNoCity = true;
            "~You don't think so. Maybe I should move on. Never thought about that.~";
        }
        if (self.cityGo) "~Make up your mind, will you?~";
        if (self.useDoor) "~Don't be rude.~";
        "~I'm sorry you disagree.~";
  ];
