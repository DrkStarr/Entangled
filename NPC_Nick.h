! Character Diamond
! 1: Ambitious - Plays Guitar, Wants To Be A Rock Star - Is A Bartender
! 2: Cocky
! 3: Quicky Wit - Works As A Bartender
! 4: Dishonest - Brags

! ---------------------------------------------------------------------------- !
!       NICK. 06/09/17
!
! Born: 1957
! Age: 23

  Object  -> theTavernNick "bartender"
    with  name 'nick' 'bartender' 'dude' 'pretty' 'boy' 'man' 'guy',
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
          ],
          before [ w1;
              AskCreatureFor:
                  if (theTavernHarry.pissedOff) iNickLeave++;
                  wn = consult_from;
                  w1 = NextWord();
                  switch (w1) {
                      'cold', 'drink', 'drinks', 'bottle', 'alcohol', 'booze', 'whiskey', 'whisky', 'scotch', 'vodka', 'shot':
                          if (dollarBill in player)
                              "Seeing the dollar in your hand, he says, ~yeah. That's still not enough. They're two dollars a shot.~";
                          if (theTavernNick.askForDrink) theTavernNick.dontKillAskForDrink = true;
                          self.askForDrink = true;
                          if (self.askNickForWhiskey) "~Ah, a little cash friend. I can't give 'em away for free.~";
                          self.askNickForWhiskey = true;
                          "~No problem. It'll cost you two dollars a shot.~";
                      'beer':
                          if (theTavernNick.askForDrink) theTavernNick.dontKillAskForDrink = true;
                          self.askForDrink = true;
                          if (self.askNickForBeer) "~They're a buck and a half apiece. Do you want one or not?~";
                          self.askNickForBeer = true;
                          "~'Round here bottles are a buck and a half apiece.~";
                      'food', 'burger', 'burgers':
                          if (self.kitchenClosed) "~Like I said. The kitchen's closed.~";
                          self.kitchenClosed = true;
                          "~The kitchen is closed right now. If you want to buy something come back later.~";
                      'change', 'quarters', 'quarter':
                          "~I'd give you some, but we don't have any to spare. Most people pay with bills.~";
                      'name':
                          return AskNickAboutName();
                  }
                  return NickResponse();
              Examine:
                  "The bartender looks too young to be serving drinks. He smiles as you look him over,
                  confident in his skills and looks.";
              Kiss:
                  "~Oh. Come on. Grow up. I'm not a teenager anymore.~";
              Talk:
                  if (theTavernHarry.pissedOff) iNickLeave++;
                  print "[You can try ";
                  if (self.askAboutBand) {
                      print "ASK BARTENDER ABOUT VAGABONDS";
                  } else {
                      print "ASK BARTENDER ABOUT BAND";
                  }
                  print " or ";
                  if (self.askMusic) {
                      if (self.askMaiden) {
                          print "ASK BARTENDER ABOUT STEVE";
                      } else {
                          print "ASK BARTENDER ABOUT MAIDEN";
                      }
                  } else {
                      print "ASK BARTENDER ABOUT MUSIC";
                  }
                  ". There are also lots of other things too.]";
              Hello:
                  if (theTavernHarry.pissedOff) iNickLeave++;
                  if (self.askForDrink) self.dontKillAskForDrink = true;
                  self.askForDrink = true;
                  "~What's your poison?~ the bartender asks.";
              Eat, Taste:
                  "What? Are you a cannibal? I know you're not that hungry.";
              WaveObject:
                  if (self.askForDrink) self.dontKillAskForDrink = true;
                  self.askForDrink = true;
                  if (theTavernHarry in theTavern) "~We're not that busy. Can I get you anything?~";
                  "~No one's even here. Can I get you anything?~";
              Take:
                  "You know he's not an object?";
              Attack, Blow, Burn, Buy, Climb, Close, Cut, Dig, Drink, Eat, Empty, Enter, Exit, GetOff, Go, JumpOver, Kick, Kiss, Listen, LookUnder, Open:
                  "You can't do that. He's behind the bar.";
              Push, PushDir, Pull, Read, Remove, Rub, Search, Set, SetTo, SmellNoun, Squeeze, Swing, SwitchOn, SwitchOff, Take, Talk, Taste, Tie, Touch, Transfer, Turn, Unlock, Wave:
                  "You can't do that. He's behind the bar.";
          ],
          life [ w1 w2;
              Answer:
                  switch(noun) {
                      t_hi: <<Hello self>>;
                      t_yes: if (theTavernHarry.pissedOff) iNickLeave++;
                             if (self.askForDrink) "~That'd be two dollars a shot.~";
                             "~Glad to hear it.~";
                      t_no: if (theTavernHarry.pissedOff) iNickLeave++;
                            if (self.askForDrink) "~Then why did you even come into this bar?~";
                            "~If you say so.~";
                      t_good: if (theTavernHarry.pissedOff) iNickLeave++;
                              if (self.answerGood) "~Always glad to hear that.~";
                              self.answerGood = true;
                              if (self.askForDrink) self.dontKillAskForDrink = true;
                              self.askForDrink = true;
                              "~Always glad to hear that. Let's celebrate with a drink.~";
                      t_bad: if (theTavernHarry.pissedOff) iNickLeave++;
                             if (self.answerGood) "~I'm sorry. Times are tough.~";
                             self.answerGood = true;
                             if (self.askForDrink) self.dontKillAskForDrink = true;
                             self.askForDrink = true;
                             "~I'm sorry times are tough. Maybe a drink will help.~";
                      t_booze, t_whiskey, t_scotch, t_vodka, t_jack:
                          if (theTavernHarry.pissedOff) iNickLeave++;
                          if (self.askForDrink) "~That'd be two dollars a shot.~";
                      t_sorry:
                          if (theTavernHarry.pissedOff) iNickLeave++;
                          if (self.tellSorryHarry) "~What? Over Harry? I'm sure he'll get over it.~";
                          "~I'm sure it's not worth mentioning.~";
                      t_thanks:
                          if (theTavernHarry.pissedOff) iNickLeave++;
                          "~Any time.~";
                      default:
                          return NickResponse();
                  }
              Ask:
                  if (theTavernHarry.pissedOff) iNickLeave++;
                  wn = consult_from;
                  w1 = NextWord();
                  w2 = NextWord();
                  if (w1 == 'live' ) {
                      if (w2 == 'music' ) {
                          return AskNickBand();
                      }
                  }
                  switch (w1) {
                      'halloween', 'samhain':
                          "~It's coming up. I used to love it when I was a kid. Now I don't care so much.~";
                      'candy':
                          "~I don't know. I like them all, but I am partial to Reese's.~";
                      'bowling', 'alley':
                          "~They might have cheap drinks over there if you want to listen to balls crack all
                          night, but it's enough to give you a headache. Over here, we like to rock.~";
                      'house', 'abandoned':
                          "~I know the place. It's behind the alley. And nasty. I think that bum lives out there. It's pretty worn down.~";
                      'amy', 'clerk', 'girl':
                          "~I see that clerk every time I go over to the drug store. She seems weird.
                          She always keeps to herself, reading or writing. I don't get it.~";
                      'steve':
                          "~Steve. Yeah that guy. He plays for Wild Orchid. Thinks he's better than me on guitar, but I'll show him up in L.A.~";
                      'wild', 'orchid':
                          "~They're nothing. Just a poser band that's going nowhere.~";
                      'amp', 'rig', 'marshall', 'half', 'stack', 'half-stack', 'head':
                          "~That's my rig on stage. I let the locals play through it as long as I can sit in.
                          It has a great sound with a modded head and special tubes from England.~";
                      'bar', 'the', 'tavern':
                          "~It's a little slow in here, but I don't mind. I can take care of a few things.
                          Just so you know. We close at 2 am.~";
                      'band', 'bands', 'entertainment':
                          return AskNickBand();
                      'change', 'quarters', 'quarter':
                          "~I'd give you some, but we don't have any to spare. Most people pay with bills.~";
                      'city', 'town', 'sunnybrook':
                          "~Sunnybrook's an average little town. I want to be where the action is.
                          I'm headed out to L.A. Big music scene out there.~";
                      'current', 'date', 'year':
                          "~You know what they say. We could all could be dead tomorrow. So you gotta
                          live for today. Right?~";
                      'darren':
                          "~He's another bartender that works here. He's older and rides my ass.
                          I've gotten into with him, but what can I do?~";
                      'dog', 'doberman':
                          print "~Yeah, Harry ";
                          if (theTavernHarry in theTavern) print "here ";
                          "knows Miller better than I do, but I know he can't take care of that dog.
                          Needs to feed the beast. You shouldn't keep 'em mean by starving 'em.~";
                      'doorman':
                          "~What? The guy that works over at Highland Towers? He's not so bad when he's not working. Tips well too.~";
                      'complex', 'high-rise', 'highrise', 'highland', 'towers', 'apartment', 'apartments':
                          "~I don't get over to Highland Towers much. I've been invited to a few parties, but
                          those people aren't my type. A little stuffy. If you know what I mean.~";
                      'drink', 'drinks', 'bottle', 'alcohol', 'booze', 'whiskey', 'whisky', 'scotch', 'vodka', 'beer', 'jack', 'daniel', 'daniels', 'daniel^s', 'daniel?s', 'shot':
                          if (dollarBill in player)
                              "Seeing the dollar in your hand, he says, ~yeah. That's still not enough. They're two dollars a shot.~";
                          if (theTavernNick.askForDrink) theTavernNick.dontKillAskForDrink = true;
                          self.askForDrink = true;
                          if (self.askNickForDrink)
                              "~A lot of people around here like whiskey, not my thing.
                              But if you want something, ask for it.~";
                          self.askNickForDrink = true;
                          "~We've got all sorts of stuff. Show me some cash. I'll hook you up.~";
                      '8-track', 'tape', 'deck', 'cartridge':
                          print "~Yeah. There's an 8-track up there on stage. Perfect for in here. It'll play Maiden all night";
                          if (self.askMaiden) ".~";
                          self.askMaiden = true;
                          ", I made the tape myself.~";
                      'food', 'burger', 'burgers', 'kitchen':
                          if (self.kitchenClosed) "~Like I said, the kitchen's closed.~";
                          self.kitchenClosed = true;
                          "~The kitchen is closed. If you're looking for something to eat, go somewhere else.~";
                      'guitar', 'ax', 'axe':
                          if (self.askAboutGuitar) "~That's my baby. Don't even ask me about it.~";
                          self.askAboutGuitar = true;
                          "~I have a '58 Les Paul Sunburst, a fantastic guitar that has such sustain. Hit that
                          note, and yeah. I don't even like people looking at it.~";
                      'harry', 'old', 'guy', 'patron', 'person':
                          if (theTavernHarry in theTavern) "~Harry here? He's a good guy, don't let him get to you.~";
                          if (self.harryLeftOnOwn) {
                              print "~Harry? He's a regular. Comes by every night. Leaves around ";
                              switch (iHourHarryLeaves) {
                                  7: print "8 pm";
                                  8: print "9 pm";
                                  9: print "10 pm";
                                  10: print "11 pm";
                                  11: print "12 am";
                                  12: print "1 am";
                                  default: print "2 am";
                              }
                              ". Might drink a little too much though.~";
                          }
                          "~Harry? He's a good guy. Too bad you ended up getting to him.~";
                      'jerry', 'attendant':
                          "~That kid over at the gas station? Too young to ever come in here.
                          Plus, I don't own a car, so I barely see him.~";
                      'judy':
                          self.judyFirstTime = true;
                          print "~Judy? No, I haven't heard of her";
                          if (self.samFirstTime) print " either";
                          ".~";
                      'los', 'angeles', 'la':
                          "~I got a friend that lives over on Sunset. He says it's starting to happen out
                          there big for rock. I'm gonna shred the scales. You'll see.~";
                      'locals':
                          "~There's a couple of local bands that play around here. Surprising for a small town
                          like this. I play with the Vagabonds, mostly. It's easy to sit in with them.~";
                      'library':
                          "~Reading is not my thing. I'm a musician, and I'm gonna make it in Rock. I never get over there.~";
                      'mabel':
                          "~What? The old lady that works the pharmacy? I think she settled and is bitter now.
                          But who am I to say?~";
                      'iron', 'maiden':
                          self.askMaiden = true;
                          "~I heard about these guys from another guitar player around here. Steve.
                          He's big into the whole import thing. Maiden caught my attention when he
                          played it for me. I made a copy on 8-track. That's what's playing right now.~";
                      'music', 'tunes', 'heavy', 'metal', 'rock':
                          self.askMusic = true;
                          "~You like it? It's an import from overseas. A new band called Iron Maiden. The mix
                          is a little rough. You know how it is, new band starting out and all. But these
                          guys rock.~";
                      'name':
                          return AskNickAboutName();
                      'bum', 'ed', 'eddie':
                          "~You mean Ed? The bum that lives over in the park? I let him in here every now and
                          then. Try to help him out. He's become a sort of fixture.~";
                      'time', 'machine', 'note', 'notes': "You better keep that information to yourself.";
                      'covid', 'bug', 'corona', 'coronavirus', 'virus': "You should keep that information to yourself.";
                      'nancy', 'punk':
                          if (self.nameNancy) "~Nancy? Maybe she would go for a guy like me.~";
                          self.nameNancy = true;
                          "~What? The girl that works down at the bowling alley? Yeah. She's a fox. Might ask
                          her out, but I'm sure she gets hit on all the time.~";
                      'nick', 'bartender', 'pretty', 'boy', 'himself', 'him', 'dude', 'man':
                          "~I'm just working here 'til I head out to L.A. I play the hell out of the guitar, and that amp
                          over there sings. It's a special import from England. I got some rare tubes in that thing.~";
                      'trailer', 'park':
                          if (self.askForDrink) self.dontKillAskForDrink = true;
                          self.askForDrink = true;
                          "~I don't see many people from the trailer park in here. They can't afford what we
                          have to offer. So. Are you going to buy a drink?~";
                      'pharmacy':
                          "~I don't get sick. But I do know Mabel and she's sour as grapes.~";
                      'phil', 'phill':
                          "~He's that old fogey who works over at the bowling alley, not a bad guy.
                          He helps Bob run the place, but the alley is stale. If you want a real bar, come
                          to The Tavern. We even have live music most nights.~";
                      'bob':
                          "~What? The owner of the alley? He must be in his fifties, and I heard he handles things over at the bar during the day.~";
                      'sam':
                          self.samFirstTime = true;
                          print "~Sam? I can't say I've heard of him";
                          if (self.judyFirstTime) print " either";
                          print ".";
                          return AskMultiAboutSam();
                      'art', 'gallery':
                          "~They seem cool enough next door. They never complain about the music.~";
                      'sarah', 'curator', 'hippie':
                          "~You know I see her now and then when she's closing up late, but I've
                          never talked to her. Not sure if she's into the whole rock thing.~";
                      'scientist', 'mark', 'tom':
                          print "~No one like that has been in here";
                          if (self.samFirstTime || self.judyFirstTime) ". Guess I can't help you tonight.~";
                          ".~";
                      'school', 'schooling':
                          "~School was never my thing. Unless it was art class. I had fun messing around.
                          Plus the art teacher was hot.~";
                      'college':
                          "~College is a waste. Why would I want to do that. I got a good thing
                          going in music. You watch. I'm going to make it out of this town.~";
                      'post', 'office':
                          "~We get more mail than we should from the post office. Most of its junk
                          and I chuck it before anybody sees it.~";
                      'yard', 'junkyard', 'millers', 'miller', 'miller^s', 'miller?s':
                          "~They have a beautiful Doberman over there, but they don't take care of him.
                          The beast's unhinged.~";
                      'gas', 'station':
                          "~Some musicians end up working in places like that to get by. I figure
                          it's smarter to be closer to the action.~";
                      'convenience', 'drug', 'store':
                          "~Doesn't Amy work over there? I don't get over there much. She trips me out.
                          How can you read all the time like that? I don't know.~";
                      'madame', 'sorra', 'gypsy', 'fortune-teller', 'fortune', 'teller':
                          print "~That old fortune-teller. She's a snake. ";
                          if (theTavernHarry in theTavern) "Ask Harry here. He'll tell you.~";
                          "If Harry was here. He'd tell you.~";
                      'stage', 'riser':
                          if (self.askAboutStage) "~What's there to know? When you're up there, all eyes are on you.~";
                          self.askAboutStage = true;
                          "~The stage?~ he asks, ~might not be that big, and the room doesn't hold that many,
                          but we all have a good time in here.~";
                      'vacuum', 'tube', 'tubes':
                          "~You into tubes? I got some rare ones in that rig. I imported that head from England. Quality stuff there.~";
                      'work', 'job', 'shop', 'place':
                          "~I like bartending. Ya meet all sorts of people.~";
                      'vagabonds':
                          if (self.askAboutVagabonds) "~Are you writing a book? They're just an old blues band.~";
                          self.askAboutVagabonds = true;
                          "~They're an old blues band that plays around here. A couple of real cool cats. If you stop 'round
                          next week, I'll introduce them.~";
                      'bus':
                          "~I never get over to Melville. The bus will take you straight there,
                          but I have no reason to go.~";
                      'melville', 'melvill':
                          "~We get a few customers from Melville in here. They usually come in on the
                          weekend after they've been paid. Though they're a bit stingy.~";
                      'yukypah', 'heef', 'statue':
                          "~What? The statue in the park? Never got into why people are so into that thing.
                          He's supposed to be some great hero. But who knows?~";
                      'plug', 'spark', 'sparkplug', 'fuse':
                          "~Sorry. I don't work on cars, friend. If you're looking for something like that, try over at the gas station.~";
                      'shard', 'crystal', 'crystals':
                          "~If you go for that sort of thing, try the place next door. It's run by a hippie chick
                          that's into that stuff.~";
                      'cigarette', 'cigarettes', 'cig', 'cigs', 'fag', 'fags', 'smokes':
                          "~Sorry. We don't have any at the bar. That vending machine does, but we don't carry change either.~";
                      'me', 'self', 'yourself':
                          "~Yeah. I think I've seen you before. You know how it is, a lot of people come and go.~";
                      'him', 'himself', 'her', 'herself', 'them':
                          "At the moment, even the simplest questions are confusing.";
                      default:
                          return (NickResponse());
                  }
              Tell:
                  if (theTavernHarry.pissedOff) iNickLeave++;
                  wn = consult_from;
                  w1 = NextWord();
                  switch(w1) {
                      'hi', 'hello', 'hola', 'greetings':
                          <<Hello self>>;
                      'yes', 'please', 'ok':
                          if (self.askForDrink) "~That'd be two dollars a shot.~";
                          "~Glad to hear it.~";
                      'no':
                          if (self.askForDrink) "~Then why did you even come into this bar?~";
                          "~If you say so.~";
                      'good':
                          if (self.answerGood) "~Always glad to hear that.~";
                          self.answerGood = true;
                          if (self.askForDrink) self.dontKillAskForDrink = true;
                          self.askForDrink = true;
                          "~Always glad to hear that, let's celebrate with a drink.~";
                      'bad':
                          if (self.answerGood) "~I'm sorry, times are tough.~";
                          self.answerGood = true;
                          if (self.askForDrink) self.dontKillAskForDrink = true;
                          self.askForDrink = true;
                          "~I'm sorry times are tough. Maybe a drink will help.~";
                      'time', 'machine', 'note', 'notes', 'house', 'abandoned', 'date', 'year':
                          "You better keep that information to yourself.";
                      'covid', 'bug', 'corona', 'coronavirus', 'virus': "You should keep that information to yourself.";
                      'watch', 'digital', 'casio':
                          "~I'm sure it's worth something to you, but look at that thing. The date's busted.
                          Please. Peddle it somewhere else.~";
                      'him', 'himself', 'her', 'herself', 'them':
                          "At the moment, even the simplest statements are confusing.";
                      'sorry':
                          if (self.tellSorryHarry) "~What? Over Harry? I'm sure he'll get over it.~";
                          "~I'm sure it's not worth mentioning.~";
                      'thanks', 'thank':
                          "~Anytime.~";
                      default:
                          "~Keep it to yourself. I'm not worried about it.~";
                  }
          ],
          orders [;
              Hello:
                  <<Hello self>>;
              Give:
                  if (noun == theTavernBooze) {
                      if (theTavernHarry.pissedOff) iNickLeave++;
                      if (second == theTavernHarry) {
                          if (theTavernHarry in theTavern) "~He's had one too many. Don't you think?~";
                      }
                      if (second == SelfPlayer) "~Why don't you pay up first. This isn't a charity.~";
                      "~I'm not just going to give it away.~";
                  }
              Open:
                  if (theTavernHarry.pissedOff) iNickLeave++;
                  if (noun == theTavernBooze)
                      "~Not before you buy it.~";
                  "~Oh yeah. I don't think so. What were we talking about again?~";
              Strong: "The bartender ignores you.";
          ],
          askForDrink false,
          askAboutGuitar false,
          askAboutStage false,
          askAboutVagabonds false,
          dontKillAskForDrink false,
          askNickForDrink false,
          askNickForBeer false,
          askNickForWhiskey false,
          harryLeftOnOwn false,
          kitchenClosed false,
          nameNancy false,
          answerGood false,
          samFirstTime false,
          judyFirstTime false,
          nameFirstTime false,
          askMusic false,
          askMaiden false,
          tellSorryHarry false,
          askAboutBand false,
    has   animate male concealed;

  [ NickResponse;
        if (theTavernHarry in theTavern) "~Sorry. Can't help you there.~";
        if (theTavernNick.askForDrink) theTavernNick.dontKillAskForDrink = true;
        theTavernNick.askForDrink = true;
        "~Can't help you there, but what about a drink?~";
  ];

  [ AskNickAboutName;
        SelfPlayer.knowNick = true;
        if (theTavernNick.nameFirstTime) "~Nick's the name. Don't forget it. I'm going to be big someday.~";
        theTavernNick.nameFirstTime = true;
        iPeople++;
        "~They all call me Nick. I haven't been working the bar for long, and I don't plan to stay between you and me. Everybody here is cool.
        I even get to sit in with the bands some nights. But I'm headed out to L.A. Music is in my soul.~";
  ];


  [ AskNickBand;
        theTavernNick.askAboutBand = true;
        "~Sorry. There's no band tonight. We usually have one, but you know how musicians are.
        I wish the Vagabonds were here. I could sit in with them.~";

  ];
