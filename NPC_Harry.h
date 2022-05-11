! Speach: cuts out Hs: 'er / t'is  =  her / this
!  'bout / ya' = about / you

! Harry = Born in 1926
! Harry = 15 - 1941 - Peral Harbor
! Harry = 18 - 1944 - USMC
! Harry = 19 - 1945 - Fights In Battle of Okinawa
! Harry = 19 - Comes Home After The War - Marries Martha
! Harry = 54 Past Time
! Harry = 94 Current Time
!
! Harry needs to drop the H's in his speech. So Harry would call himself 'arry
!

! Character Diamond
! 1: Mean, Bitter About The War & Bitter About His Wifes Death
! 2: Jokes Around About It To Cover It Up
! 3: Addict - Alcohol
! 4: Hot Headed

! ---------------------------------------------------------------------------- !
!       HARRY. 06/09/17
!
! Age: 54

  Object  -> theTavernHarry "old guy"
    with  name 'old' 'man' 'oldman' 'oldguy' 'guy' 'harry' 'patron' 'person' 'older',
          describe [;
              rtrue;
          ],
          daemon [;
              iWait++;
              if (iWait == 2) {
                  StopDaemon(self);
                  iWait = 0;
                  if (self in outsideJoesBar) {
                      remove self;
                      if (SelfPlayer in outsideJoesBar) {
                          "^The old guy takes off down the street entering the subdivision to the
                          south. Slowly he makes his way through the streets before entering one
                          of the homes.";
                      }
                  }
              }
          ],
          before [ w1;
              AskCreatureFor:
                  if (self.pissedOff) "~Go bother someone else.~";
                  wn = consult_from;
                  w1 = NextWord();
                  switch (w1) {
                      'cold', 'drink', 'drinks', 'bottle', 'whiskey', 'alcohol', 'booze':
                          iOldManAnger++;
                          "~Go find your own!~";
                      'food', 'burger', 'burgers':
                          iOldManAnger++;
                          "~What do ya' think? I'm going to order ya' some? Get out of 'ere.~";
                      'name':
                          return AskHarryAboutName();
                      'change', 'quarters', 'quarter':
                          "~I don't have any change. Go bother someone else.~";
                  }
                  return HarryResponse();
              Examine:
                  print "The guy's older, hair has gone white, now in his 50s. He wears overalls.
                  A crusty set worn-in with dirt and grease";
                  if (self in theTavern) ". Nursing a whiskey, he keeps to himself.";
                  ".";
              Search, Climb:
                  "I don't think he would care for that.";
              Talk:
                  if (self.pissedOff) "~Go bother someone else.~";
                  print "[You can try ";
                  if (self.askAboutBar) {
                      print "ASK PATRON ABOUT BARTENDER";
                  } else {
                      print "ASK PATRON ABOUT BAR";
                  }
                  print " or ";
                  if (self.askAboutDrink) {
                      if (self.askAboutWife) {
                          print "ASK PATRON ABOUT ARSENIC";
                      } else {
                          print "ASK PATRON ABOUT WIFE";
                      }
                  } else {
                      print "ASK PATRON ABOUT DRINK";
                  }
                  ". There are also lots of other things too.]";
              Hello:
                  if (self.pissedOff) "~Go bother someone else.~";
                  "~Go make friendly with somebody else.~";
              Eat, Taste:
                  "What? Are you a cannibal? I know you're not that hungry.";
              SmellNoun:
                  "You'd look strange smelling him.";
              Kiss:
                  "~You got the wrong person, friend.~";
              Rub, Touch, Pet:
                  if (self in outsideJoesBar) "~'ey, what are you doing?~";
                  iOldManAnger++;
                  "~Get back,~ the old man says, reseating himself on the stool.";
              Push:
                  if (self in outsideJoesBar) "~'ey, what are you doing?~";
                  iOldManAnger++;
                  if (theTavernStool.sitOn) {
                      theTavernStool.sitOn = false;
                      print "(first getting off the stool)^";
                  }
                  print "You bump into him by mistake.^";
                  switch(iOldManAnger) {
                      1: "^~'ey, what are you doing? I almost spilled my drink.~";
                      2: "^~Back off, there's plenty of room in this bar.~";
                      3: "^~What's your problem?~";
                  }
              WaveObject:
                  if (self in outsideJoesBar) "~I see ya'.~";
                  "~I see ya'. But I'm not the one serving drinks.~";
              Take:
                  "You know he's not an object?";
              Pull:
                  "~Get your hands off.~";
          ],
          life [ w1;
              Answer:
                  switch(noun) {
                      t_hi: <<Hello self>>;
                      t_yes: "~I'm excited for ya'.~";
                      t_no: "~Now ya' know 'ow I feel.~";
                      t_good: print "~Yeah. Real 'appy for ya'";
                              if (self.takeSip) ".~";
                              self.takeSip = true;
                              ",~ he says, taking a sip.";
                      t_bad: "~That's 'ow we all feel.~";
                      t_thanks: "~Don't thank me.~";
                      default:
                          return HarryResponse();
                  }
              Ask:
                  if (self.pissedOff) "~Go bother someone else.~";
                  wn = consult_from;
                  w1 = NextWord();
                  switch (w1) {
                      'halloween', 'samhain':
                          "~I hate this time of year. The kids are bad enough already. And I don't want them ringing my bell.~";
                      'candy':
                          "~I'm not passing any out. I don't want to see those brats.~";
                      'bowling', 'alley':
                          "~Do I look like the type that bowls? Plus Phil, that bartender, he needs
                          to get a spine.~";
                      'house', 'abandoned':
                          "~I  know of it, but what about it? I don't go over to the alley. Let alone behind it.~";
                      'amy', 'clerk', 'girl':
                          "~That girl at the drug store? She's pretty useless. Real introvert.
                          Always reading. I doubt that she amounts to much.~";
                      'convenience', 'drug', 'store':
                          "~Yeah. I buy my lottery tickets over there. But that clerk is worthless.
                          Always reading comics. Won't sell you any beer.~";
                      'school', 'schooling', 'college':
                          iOldManAnger++;
                          "~What does it matter whether I went to school or not? Why don't you get out of 'ere.~";
                      'post', 'office':
                          "~The post office is older than I am. But why do you care? Don't tell me.
                          I know. You're just trying to make conversation.~";
                      'yard', 'junkyard', 'millers', 'miller', 'miller^s', 'miller?s':
                          "~Old Miller he's a real character. Doesn't drink in 'ere. He's too cheap.~";
                      'trailer', 'park':
                          "~What about the trailer park? No one worth their salt has come for there.~";
                      'dog', 'doberman':
                          "~Miller doesn't know how to take care of that thing. Uses him as cheap security.
                          Barely feeds him.~";
                      'arsenic':
                          "~Ya know. A little dab will do ya. Every day, for long enough time,
                          will bury any man.~";
                      'bar', 'the', 'tavern', 'place':
                          self.askAboutBar = true;
                          "~The Tavern? Great place to drown your sorrows for a while.
                          I've been coming 'ere for years. Seen 'em trade out a few bartenders.
                          Nick 'ere is a bit green, but his 'eart is in the right place.~";
                      'wife', 'martha':
                          self.askAboutWife = true;
                          "~Martha? She was the best I could 'ope for, even though she was
                          trying to kill me. Guess I didn't make the right choice there. She
                          went early though. Bad ticker.~";
                      'current', 'date', 'year':
                          "~Times have changed. I've seen people go from helping one another
                          to loving one another to hating each other. It'll come around again.
                          I'm sure.~";
                      'doorman':
                          "~I don't live there. I don't go over there. And I don't mess with that guy.
                          I keep to myself as people should.~";
                      'complex', 'high-rise', 'highrise', 'highland', 'towers', 'apartment', 'apartments':
                          "~I wouldn't live in that complex. It costs too much. In my day, we watched how
                          we spent our cash. It'd be like throwing away money.~";
                      'judy':
                          "~Nope, don't know 'er.~";
                      'harry', 'patron', 'name', 'himself', 'old', 'guy', 'him', 'oldman', 'oldguy', 'person':
                          return AskHarryAboutName();
                      'library':
                          "~Do I look like someone who likes to read. Come on.~";
                      'time', 'machine', 'note', 'notes': "You better keep that information to yourself.";
                      'covid', 'bug', 'corona', 'coronavirus', 'virus': "You should keep that information to yourself.";
                      'mabel':
                          "~I know her. She was friends with my wife. And a pain in my side too.
                          Always riding me about my drinking. Like she'd know.~";
                      'pharmacy':
                          "~Mabel works over there. Always givin' me a hard time.
                          Making me wait on my 'scripts. She knew my wife, ya' know.~";
                      'nancy', 'punk':
                          if (self.nameNancy) "~Bah. She's too young for me.~";
                          self.nameNancy = true;
                          "~Nancy? She's a real doll. Works over at the bowling alley. She stops
                          by now and then. I think she might have a thing for Nick.~";
                      'nick', 'bartender', 'pretty', 'boy':
                          "~Nick's a great bartender. Doesn't ask too many questions like some people.~";
                      'sam', 'scientist', 'mark', 'tom':
                          print "~Never heard of 'im.";
                          return AskMultiAboutSam();
                      'sarah', 'curator', 'hippie':
                          "~She's a hippy if I've ever seen one. They're going to ruin the world I tell ya'.~";
                      'bob':
                          "~Bob? Hm. That guy can be as ornery as me at times.~";
                      'art', 'gallery':
                          "~The place next door? I don't go for the whole hippy thing. I don't get it.
                          And the smell. It stinks over there.~";
                      'madame', 'sorra', 'gypsy', 'fortune-teller', 'fortune', 'teller':
                          "~She's gotta be older than me. In 'er sixties at least. Creeps most people out.
                          But I know she's a scam. They all can read you like a book, but know nothing
                          'bout your future.~";
                      'phil', 'phill':
                          "~I haven't bought a drink from Phil in years. That guy's a pushover.
                          Won't stand up to his convictions.~";
                      'work', 'job':
                          iOldManAnger++;
                          "~Ya' always this nosy.~";
                      'city', 'town', 'sunnybrook':
                          "~Sunnybrook's nice. Don't see a lot of communities like t'is.
                          I've lived 'ere probably longer than I should, but the wife
                          tied me to this place. Too old to move on now.~";
                      'melville', 'melvill':
                          "~I get over there now and then, my cousin lives there, but it's a dirty city with nasty people.~";
                      'bus':
                          "~I've taken it to get over to Melville. I have a cousin that lives over there. He's not doing too good.~";
                      'cousin':
                          "~He's got cancer eating him up. I try to stop by, but I hate taking the bus.~";
                      'alcohol', 'booze', 'drink', 'whiskey':
                          if (self.askAboutDrink) "~As I said. I love to get lost in my cups.~";
                          self.askAboutDrink = true;
                          "~Yea'. I love to get lost in my cups. The old bat used to say I
                          drank too much, shows 'er. Who's laughing now.~
                          ^^You try to smile, but it comes across as an awkward grin.
                          ^^~Ah, don't worry 'bout it. I swear she was trying to kill me.
                          Probably put arsenic in my coffee every morning.~";
                      'change', 'quarters', 'quarter':
                          "~I don't have any change. Get out of 'ere.~";
                      'bum', 'ed', 'eddie':
                          "~That guy pisses me off too. Always expecting a handout. Who has he
                          helped out in this town? Hmm. What's the world coming to?~";
                      'jerry', 'attendant', 'gas', 'station':
                          "~That wet behind the ears kid that works over at the station. He's soft.~";
                      'yukypah', 'heef', 'statue':
                          "~What? The statue? They say it's of some founder that goes back to the 1800s. Who cares?~";
                      'plug', 'spark', 'sparkplug', 'fuse':
                          "~What would I be doing with a spark plug?~";
                      'shard', 'crystal', 'crystals':
                          "~Are you into crystals? I bet you are some sort of hippie. You belong next door.~";
                      'vacuum', 'tube', 'tubes':
                          "~Nick might know. He's always going on about that sort of thing. I just nod my head.~";
                      'me', 'self', 'yourself':
                          "~Hmm. What about you? You're not a regular here.~";
                      'him', 'himself', 'her', 'herself', 'them':
                          "At the moment, even the simplest questions are confusing.";
                      default:
                          return (HarryResponse());
                  }
              Tell:
                  wn = consult_from;
                  w1 = NextWord();
                  switch(w1) {
                      'hi', 'hello', 'hola', 'greetings':
                          <<Hello self>>;
                      'yes', 'please', 'ok':
                          "~I'm excited for ya'.~";
                      'no':
                          "~Now ya' know 'ow I feel.~";
                      'good':
                          print "~Yeah, real 'appy for ya'";
                          if (self.takeSip) ".~";
                          self.takeSip = true;
                          ",~ he says, taking a sip.";
                      'thanks', 'thank': "~Don't thank me.~";
                      'bad':
                          "~That's 'ow we all feel.~";
                      'time', 'machine', 'note', 'notes', 'house', 'abandoned', 'date', 'year':
                          "You better keep that information to yourself.";
                      'covid', 'bug', 'corona', 'coronavirus', 'virus': "You should keep that information to yourself.";
                      'him', 'himself', 'her', 'herself', 'them':
                          "At the moment, even the simplest statements are confusing.";
                      'harry':
                          iOldManAnger++;
                          if (self.tellAboutHarry) "~Look. I said get out of 'ere.~";
                          self.tellAboutHarry = true;
                          "~So what. Now ya' t'ink ya' know me or somet'ing? Why don't ya'
                          get out of 'ere. Ya' just annoy me.~";
                      default:
                          "~Do I even know ya'? Go bother someone else.~";
                  }
          ],
          orders [;
              if (self.pissedOff) "~Go bother someone else.~";
              Hello:
                  <<Hello self>>;
              Give:
                  if (noun == theTavernDrink) {
                      print "~Pushy ";
                      if (self.nameFirstTime) print "too";
                      else print "aren't ya'";
                      ". Try talking to Nick if ya' want some booze.~";
                  }
                  "~Ah, get out of 'ere.~";
              Open:
                  if (noun == theTavernBooze)
                      "~I don't run t'is place. Talk to Nick.~";
                  "~Go push someone else around.~";
              Strong:
                  iOldManAnger = iOldManAnger + 3;
                  "~Yeah,~ the old man says, glaring at you.";
          ],
          harryScored false,
          takeSip false,
          nameNancy false,
          pissedOff false,
          samFirstTime false,
          judyFirstTime false,
          nameFirstTime false,
          tellAboutHarry false,
          askAboutDrink false,
          askAboutWife false,
          askAboutBar false,
     has  animate male concealed scenery;

  [ HarryResponse;
        "~Can't 'elp ya',~ the old man says, grumbling to himself.";
  ];

  [ AskHarryAboutName;
        SelfPlayer.knowHarry = true;
        if (theTavernHarry.nameFirstTime == false) {
            theTavernHarry.nameFirstTime = true;
            theTavernHarry.harryScored = true;
            iPeople++;
            "~Ya' don't need to know my name. Why don't ya' mind your own business,~ the old man grumbles.";
        }
        iOldManAnger++;
        "~I told ya'. Mind your own business,~ the old man grumbles.";
  ];
