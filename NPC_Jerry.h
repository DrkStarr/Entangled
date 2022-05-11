
! *********************************************************************************
! The attendant will watch T.V. in the past and play with his phone in current time
! *********************************************************************************

! Character Diamond
! 1: Ambitious - Wants To Be The Manager - Thinks It Sounds Good
! 2: Outgoing
! 3: Limited Knowledge - Knows Cars
! 4: Street Smart - Reads People

! Birthday is in May

! ---------------------------------------------------------------------------- !
!       JERRY. 05/16/17
! Age: 17
!

  Object  gasStationJerry "attendant"
    with  name 'jerry' 'attendant' 'man' 'guy' 'dude' 'teen' 'clerk' 'kid',
          describe [;
              rtrue;
          ],
          daemon [;
              if (self.askForCar) {
                  iAskCar++;
              }
              if (self.dontKillAskForCar) {
                  self.dontKillAskForCar = false;
              } else {
                  if (iAskCar > 1) {
                      iAskCar = 0;
                      self.askForCar = false;
                  }
              }
              if (self.askAboutCats) {
                  iAskCats++;
              }
              if (self.dontKillAskAboutCats) {
                  self.dontKillAskAboutCats = false;
              } else {
                  if (iAskCats > 1) {
                      iAskCats = 0;
                      self.askAboutCats = false;
                  }
              }
              if (self.askAboutPlug) {
                  iAskPlug++;
              }
              if (self.dontKillAskAboutPlug) {
                  self.dontKillAskAboutPlug = false;
              } else {
                  if (iAskPlug > 1) {
                      iAskPlug = 0;
                      self.askAboutPlug = false;
                  }
              }
          ],
          before [ w1;
              AskCreatureFor:
                  wn = consult_from;
                  w1 = NextWord();
                  switch (w1) {
                      'cigarette', 'cigarettes', 'cig', 'cigs', 'fag', 'fags', 'smokes':
                          "~I can sell you some cigs, but they're two dollars a pack.~";
                      'name':
                          return JerryAskForName();
                      'change', 'quarters', 'quarter':
                          "~If you bought something sure, I'd make change for you. But you're not.
                          Stop wasting my time.~";
                      'soda', 'pop', 'coke', 'cokes', 'cola':
                          return PHP();
                      'key':
                          "~I can't just let you use the bathroom. You gotta buy something. Sorry.
                          Not my rules, the bosses.~";
                      'plug', 'spare', 'part', 'parts', 'spark', 'sparkplug', 'fuse':
                          "~The boss keeps them locked up in the garage. Doesn't trust us. I can't get to them.~";
                  }
                  return JerryResponse();
              Buy:
                  if (second == gasStationCigarettes) "~Show me some cash friend and the cigarettes are all yours.~";
              Examine:
                  print "The heavyset teen pays no attention to you as he ";
                  if (self.eyesOpen) {
                      self.eyesOpen = false;
                      if (conanComic.giveToJerry) "turns back to the comic book.";
                      "turns back to the television.";
                  }
                  if (conanComic.giveToJerry) "flips through the comic book taking in the art.";
                  "watches television in the booth.";
              Talk:
                  print "[You can try ";
                  if (self.askAboutJunkyard) {
                      print "ASK ABOUT GARAGE";
                  } else {
                      if (self.askAboutAlley) {
                          print "ASK ABOUT JUNKYARD";
                      } else {
                          print "ASK ABOUT BOWLING ALLEY";
                      }
                  }
                  print " or ";
                  if (self.askAboutCar) {
                      print "ASK ABOUT ENGINE";
                  } else {
                      print "ASK ABOUT CAR";
                  }
                  print " or ";
                  if (self.askAboutWork) {
                      if (self.askAboutBoss) {
                          print "ASK ABOUT PUMPS";
                      } else {
                          print "ASK ABOUT BOSS";
                      }
                  } else {
                      print "ASK ABOUT WORK";
                  }
                  ". There are also lots of other things too.]";
              Hello:
                  if (self.eyesOpen) {
                      self.eyesOpen = false;
                      if (conanComic.giveToJerry) "~How you doing?~ the teen asks, lowering his eyes back to the comic book.";
                      "~How you doing?~ the teen asks, lowering his eyes back to the television.";
                  }
                  if (conanComic.giveToJerry) "~How you doing?~ the teen asks, not lifting his eyes up from the comic book.";
                  "~How you doing?~ the teen asks, not lifting his eyes up from the television.";
              Pet:
                  "While he wouldn't appreciate that, he's also sitting in the booth.";
              Eat, Taste:
                  "What? Are you a cannibal? I know you're not that hungry.";
              WaveObject:
                  if (self.eyesOpen) {
                      "~Okay. Okay. Calm down,~ the attendant says, ~what do you want?~";
                  }
                  self.eyesOpen = true;
                  print "~Okay. Okay. Calm down,~ the attendant says looking ";
                  if (conanComic.giveToJerry) "up from the comic, ~what do you want?~";
                  "over from the television, ~what do you want?~";
              Take:
                  "You know he's not an object?";
              Attack, Blow, Burn, Buy, Climb, Close, Cut, Dig, Drink, Eat, Empty, Enter, Exit, GetOff, Go, JumpOver, Kick, Kiss, Listen, LookUnder, Open:
                  "You can't do that. He's behind Plexiglas.";
              Push, PushDir, Pull, Read, Remove, Rub, Search, Set, SetTo, SmellNoun, Squeeze, Swing, SwitchOn, SwitchOff, Take, Talk, Taste, Tie, Touch, Transfer, Turn, Unlock, Wave:
                  "You can't do that. He's behind Plexiglas.";
          ],
          life [ w1;
              Answer:
                  switch(noun) {
                      t_hi: <<Hello self>>;
                      t_yes: return AnswerYesJerry();
                      t_no: return AnswerNoJerry();
                      t_goodbye: "~Catch you on the flip side.~";
                      t_sorry: "~Nothing's wrong. It's cool.~";
                      t_thanks: "~What? I did something right for once? Far out.~";
                      default:
                          return JerryResponse();
                  }
              Ask:
                  wn = consult_from;
                  w1 = NextWord();
                  switch (w1) {
                      'halloween', 'samhain':
                          "~I wish I could still go out. My Mom won't let me. She says I'm too old.~";
                      'candy':
                          "~Well. I love them all: Nerds, Sprees, Pop Rocks, Big League Chew. They're awesome.~";
                      'bowling', 'alley':
                          self.askAboutAlley = true;
                          "~It's about the only entertainment we have in this town unless you like
                          hanging out at the bar. Which I'm not old enough to do. Give me less
                          than a year and I'll be 18 though.~";
                      'house', 'abandoned':
                          if (self.askAboutHouse) "~Sorry. I shouldn't have said anything.~";
                          self.askAboutHouse = true;
                          "~You know, I shouldn't say this but, I kissed Nancy once back there. A long time ago, when we were kids. She probably forgot about it.~";
                      'boss', 'owner':
                          self.askAboutBoss = true;
                          "~He can be a real piece of work. Always checking up on me come morning.
                          Like I'm going to steal something. But I don't think he trusts anybody around here.~";
                      'car', 'mercury':
                          self.askAboutCar = true;
                          "~I'm putting that old Mercury back together. Done a lot of work already with the
                          suspension. Now I'm working on the engine. It'll purr like a kitten when I'm done.~";
                      'engine':
                          "~I had to pull the head gaskets. They're warped. Need to mill them down and reseal
                          the whole thing. Not too bad though. At least I know what I'm doing.~";
                      'radiator':
                          "~The radiator's core is solid in that Mercury. I thought about replacing it,
                          she is old and all, but it should do the job.~";
                      'plug', 'spark', 'sparkplug', 'fuse':
                          if (self.askAboutPlug) self.dontKillAskAboutPlug = true;
                          self.askAboutPlug = true;
                          "~You trying to fix that mower? The one over at the trailer park?
                          I've looked at her, and even I can't get her running.~";
                      'lawn', 'mower', 'lawnmower':
                          "~The one they keep in the shed over at the park? It never ran great.
                          I've taken that engine apart more times than I care to imagine. People
                          try to take care of it, but too many use it.~";
                      'cigarette', 'cigarettes', 'cig', 'cigs', 'fag', 'fags', 'smokes':
                          "~I can sell you some cigs, but they're two dollars a pack.~";
                      'city', 'town', 'sunnybrook':
                          "~I've grown up here. Wouldn't want to be anywhere else.~";
                      'current', 'date':
                          "~What October? It's my favorite month. I love Halloween. Look at all the candy you get.~";
                      'cold', 'drink', 'drinks', 'bottle', 'coke', 'cokes', 'cola', 'soda', 'pop':
                          "~Yeah. The boss makes me pay for them, but I don't care. I'm just buying my time 'til I can work in the garage.~";
                      'jerry':
                          if (self.nameFirtTime) {
                              self.nameFirtTime = false;
                              self.jerryFirtTime = true;
                              SelfPlayer.knowJerry = true;
                              self.jerryScored = true;
                              iPeople++;
                              "~What? You've heard of me? That makes me feel special. Sorry. I haven't heard of you.~";
                          }
                          "~I grew up in this town, great little place. I know some that want to move on. I don't see the need.~";
                      'attendant', 'man', 'dude', 'teen', 'kid', 'himself', 'him':
                          "~I grew up in this town, great little place. I know some that want to move on. I don't see the need.~";
                      'library':
                          "~Sometimes I have to go over there to do homework. I hate it.
                          I'd rather be working on an engine. If you know what I mean.~";
                      'asteroids', 'arcade', 'machine':
                          "~Oh. I'm pretty good at that thing. Asteroids is fun. But Amy is better. She's the one that has high score on it.~";
                      'pharmacy':
                          "~Mabel works over there. I quit going over to the drug store because of her.~";
                      'mabel':
                          "~What about her? Not the nicest person I can tell you that. She always
                          rides me when I go over there. So I stopped. And they have some great comics.~";
                      'name':
                          return JerryAskForName();
                      'pump', 'pumps':
                          "~We don't have full service anymore. Thank God. That would make the job so much more difficult.~";
                      'full', 'service':
                          "~Yeah. If you were driving a car you'd have to fill it on your own.~";
                      'telle', 'television', 'tv', 'tele':
                          if (conanComic.giveToJerry)
                              "~Might as well leave it off. This comic is sweet.~";
                          "~The boss lets me watch it. He doesn't mind, and the job gets done. I just have to cover the shift.~";
                      'fight':
                          "~It's a rebroadcast of last weeks fight. It's okay, but nothing like Duran vs. Leonard, that was an amazing fight.
                          Sugar Ray was defending his title and they didn't even know who won by the end. Went the full 15 rounds.~";
                      'sam':
                          print "~Sam? No. Never heard of that guy. You sure he lives around here?";
                          return AskMultiAboutSam();
                      'scientist':
                          "~Not sure who that is.~";
                      'bathroom', 'lavatory', 'washroom', 'head':
                          "~I can't just let you use the bathroom. You gotta buy something. Sorry.
                          Not my rules, the bosses.~";
                      'school', 'schooling':
                          "~I still go to high school but only for another year. Can't wait to get out.
                          Then maybe I can start to work in the garage.~";
                      'college':
                          "~That's not my thing. I'm hoping to start working in the garage after I graduate.~";
                      'post', 'office':
                          "~What about the post office? It's nice to look at and all, but nowhere to hang out.~";
                      'mark':
                          "~Sorry. No one like that works here.~";
                      'tom':
                          "~I don't know anybody like that. Maybe I can help you with something else?~";
                      'judy':
                          "~Sorry. I don't know her. Maybe you're thinking about someone else.~";
                      'garage':
                          "~It's small, and there are two cars in there. After I graduate, I need to clean it out. Then I can repair them for real, not just tinker, like with this Mercury.~";
                      'gas', 'station', 'work', 'job', 'shop', 'place':
                          print "~I like it here,~ he says ";
                          if (self.eyesOpen == false) {
                              self.eyesOpen = true;
                              print "looking up for a second";
                          } else {
                              print "with a shrug";
                          }
                          self.askAboutWork = true;
                          ", ~though the boss can be a bit of a pain. They at least let me work on the
                          cars now and then. Who knows. If I'm lucky I might make manager one day.~";
                      'manager':
                          "~We don't have a real manager that works here. It's just the owner that watches over things. And he's strict.~";
                      'the', 'tavern', 'bar':
                          "~I'll be able to drink in less than a year. So yeah. I'm looking forward to going in there.~";
                      'yard', 'junkyard', 'millers', 'miller', 'miller^s', 'miller?s':
                          self.askAboutJunkyard = true;
                          "~The junkyard? We get some big things from there. Engines, transmissions,
                          that sort of thing. But all the smaller stuff we keep locked up in the garage.~";
                      'nancy', 'punk':
                          "~She's a firey one and a real mouth on her too. She might seem nice
                          and all when she's working, but she can be a piece of work. I guess we all can
                          be at times. I have a bit of history with her too.~";
                      'history':
                          "~Ah. You know. Well. We were sweet on each other a long time ago. You know how things are. But it didn't last long.~";
                      'phil', 'phill':
                          "~I know the guy. See him when I'm over at the alley. But that's about it.
                          Never struck up a conversation or anything.~";
                      'bob':
                          "~I know Bob. The guy that runs the alley, right? He's pretty cool to me, even gives me sodas on the house whenever I'm hanging out playing the arcade machine.~";
                      'sign':
                          "~Ah. I hate having to change the price on that thing. You have to get the ladder out,
                          play with those dumb inserts. There has to be a better way. Right?~";
                      'cars':
                          "~Nothing but old junkers in that garage. Some from the '50s, I think.~";
                      'madame', 'sorra', 'gypsy', 'fortune-teller', 'fortune', 'teller':
                          if (self.askedSorra) {
                              if (self.askAboutCats) self.dontKillAskAboutCats = true;
                              self.askAboutCats = true;
                              "~I heard she's a witch that drinks the blood of cats to stay alive.
                              Don't see any cats in this town, do you?~";
                          }
                          self.askedSorra = true;
                          "~What? That old fortune-teller? Growing up here you hear a lot of strange things.
                          Who knows if any of it is true. We never see her anyways.~";
                      'art', 'gallery':
                          "~I went in there recently. Sarah had some weird piece of art in the center of the room
                          and the whole place stunk. I don't think I'm going back. Why?~";
                      'curator', 'sarah', 'hippie':
                          "~I think she lives over in the subdivision and doesn't even own a car. She's friends with my Mom.~";
                      'mom', 'mother':
                          "~She grew up in the 60s. Still a hippie. But I love her. She's all that I got.~";
                      'bum', 'ed', 'eddie':
                          "~Nice guy - comes by at night. I talk to him now and then. He keeps me company.~";
                      'harry', 'old', 'guy':
                          "~That guy is older than the hills and mean as a bear. He comes around
                          here at times, but I think it's more to mess with me than not.~";
                      'nick', 'pretty', 'boy', 'bartender':
                          "~I like Nick. He's far out. Plus, who knows, maybe he'll make it out
                          of this town. Hit it big. I'd like to see someone make it out of here.
                          Put this little town on the map.~";
                      'convenience', 'drug', 'store':
                          "~Amy works over there at night. So I keep away. And then there's Mabel
                          during the day. That place is the worst.~";
                      'trailer', 'park':
                          "~I live up there in the trailer park and everybody's nice. People just
                          trying to get by. No one has a lot of money. I'm lucky to have a steady job.~";
                      'amy', 'clerk', 'girl':
                          "~You know, she's nice and all but not my type. We've been in the same
                          grade since kindergarten and I think she likes me.~";
                      'doorman':
                          "~Everybody says to stay away from the guy. So I do. Never had a problem with him.~";
                      'complex', 'high-rise', 'highrise', 'highland', 'towers', 'apartment', 'apartments':
                          "~Big wigs live over there. And that doorman is meaner than the junkyard dog.~";
                      'dog', 'doberman':
                          "~What? That Doberman that protects Miller's Yard? Yeah. He's a mean one.
                          Take your hand off if you give him a chance.~";
                      'yukypah', 'heef', 'statue':
                          "~I had to learn about that dumb thing years ago. My dad thinks that
                          they should do something else with the land.~";
                      'change', 'quarters', 'quarter':
                          "~If you bought something sure, I'd make change for you. But you're not.
                          Stop wasting my time.~";
                      'bus':
                          "~That bus will take you to Melville. It's a dirty place from what I hear.~";
                      'melville', 'melvill':
                          "~My dad's always saying it's a nasty place. He works over there. The
                          factories spew out pollution like there's no tomorrow, according to him.~";
                      'conan', 'comic', 'book':
                          if (gasStationComic in gasStation) {
                              print "~I love these pictures. The artist is great. It's really inspiring";
                              if (self.askAboutComic){
                                  self.askAboutComic = false;
                                  ". And Red Sonja's in here. You know. I never thought about it before, but maybe I should try my hand at art. I have a lot of extra time here at the station.~";
                              }
                              ".~";
                          }
                          "~What about that?~";
                      'picture', 'pictures', 'red', 'sonja', 'drawings':
                          if (gasStationComic in gasStation) "~Yeah. Red Sonja is pretty striking. I'd love to draw like this.~";
                      'draw', 'drawing':
                          if (gasStationComic in gasStation) "~With all the extra time I have around here at night, I could get into something like this.~";
                      'extra', 'time':
                          if (gasStationComic in gasStation) "~Yeah. You know. Not a lot goes on at night. Whenever I work the dayshift, I have to look busy. So I couldn't draw.~";
                      'dayshift', 'day':
                          "~Now and then, they want me to cover things during the day. I don't mind. Sometimes they let me work on the cars around here.~";
                      'shard', 'crystal', 'crystals':
                          "~That hippie chick, the curator, she's always into that stuff.
                          Go ask her about it. We're mechanics over here.~";
                      'vacuum', 'tube', 'tubes':
                          "~We don't carry that sort of thing. And heck, I'm not sure where you could get one. Have you checked the junkyard?~";
                      'birthday':
                          "~Well. I'll be 18 in May. Be able to drink by then. Can't wait.~";
                      'candy':
                          "~We got plenty in this booth. I sneak one in now and then. M&M's are my favorite.~";
                      'booth':
                          "~Yeah. It sucks working in a confined space like this. But it's kind of cozy too.~";
                      'spare', 'part', 'parts':
                          "~The boss keeps them locked up in the garage. I can't get to them.~";
                      'key':
                          "~People always lose the key to that shed. I found it in some strange places. I don't know why they have to make it hard.~";
                      'shed':
                          self.askAboutShed = true;
                          "~Yeah. I use that shed to store a few things. Even have my bike in there.~";
                      'bike', 'bmx':
                          if (self.askAboutShed) "~My bike is a BMX. Great for getting around town, cutting through trails.~";
                          self.askAboutShed = true;
                          "~Yeah. My bike is in the shed. I try to take care of it, can't bring it into the trailer.~";
                      'me', 'self', 'yourself':
                          if (conanComic.giveToJerry) "~What about you? I'm reading something here.~";
                          "~What about you? I'm watching something here.~";
                      'time', 'notes': "You better keep that information to yourself.";
                      'covid', 'bug', 'corona', 'coronavirus', 'virus': "You should keep that information to yourself.";
                      'him', 'himself', 'her', 'herself', 'them':
                          "At the moment, even the simplest questions are confusing.";
                      default:
                          return (JerryResponse());
                  }
              Tell:
                  wn = consult_from;
                  w1 = NextWord();
                  switch(w1) {
                      'spark', 'sparkplug', 'plug', 'fuse':
                          if (shed.removeSparkPlug) "~What about the plug? I already cleaned that up.~";
                          "You think about it, but you might be able to use it.";
                      'hi', 'hello', 'hola', 'greetings':
                          <<Hello self>>;
                      'yes', 'please', 'ok':
                          return AnswerYesJerry();
                      'no':
                          return AnswerNoJerry();
                      'sorry':
                          "~Nothing's wrong. It's cool.~";
                      'goodbye', 'goodby', 'good-bye', 'bye', 'cheerio':
                          "~Catch you on the flip side.~";
                      'thanks', 'thank': "~What? I did something right for once? Far out.~";
                      'time', 'machine', 'note', 'notes', 'house', 'abandoned', 'date', 'year':
                          "You better keep that information to yourself.";
                      'covid', 'bug', 'corona', 'coronavirus', 'virus': "You should keep that information to yourself.";
                      'shed':
                          if (shed.removeSparkPlug)
                              "You tell him that you found a spark plug in the shed.^
                              ^~Do you always go around stealing things? That's not yours. You should put it back.~";
                          "~What about the shed?~";
                      'him', 'himself', 'her', 'herself', 'them':
                          "At the moment, even the simplest statements are confusing.";
                      default:
                          "~Don't know about that.~";
                  }
          ],
          orders [;
              Hello:
                  <<Hello self>>;
              Give:
                  if (noun == gasStationCigarettes)
                      "~Yeah, I can sell you some cigs, but do you have any money?~";
                  "~I doubt that you really need that.~";
              Open:
                  if (noun == gasStationBooth)
                      "~I can't do that. I'd lose my job.~";
                  "~Look, you're not my boss. Don't push me around.~";
              Strong: "The attendant ignores you.";
          ],
          jerryScored false,
          eyesOpen false,
          askedWork false,
          askedSorra false,
          jerryFirtTime false,
          nameFirtTime true,
          angryAttendant false,
          askForCar false,
          dontKillAskForCar false,
          askAboutCats false,
          dontKillAskAboutCats false,
          askAboutAlley false,
          askAboutCar false,
          askAboutWork false,
          askAboutBoss false,
          askAboutComic true,
          askAboutPlug false,
          dontKillAskAboutPlug false,
          askAboutHouse false,
          askAboutJunkyard false,
          askAboutShed false,
    has   animate male concealed;

  [ JerryResponse;
        iJerryResponse++;
        if (conanComic.giveToJerry) {
            if (iJerryResponse > 3) {
                iJerryResponse = 0;
                "~Look. I'm reading the comic you gave me. Are you going to go on all night?~";
            }
            "~Look. I'm reading the comic you gave me. And I'm not sure what you want.~";
        }
        if (iJerryResponse > 3) {
            iJerryResponse = 0;
            "~Look. I'm watching the fight here. Are you going to go on all night?~";
        }
        "~Look. I'm watching the fight here. And I'm not sure what you want.~";
  ];

  [ JerryAskForName;
        SelfPlayer.knowJerry = true;
        if (gasStationJerry.jerryFirtTime) "~You seem to already know me, but it is a small town.~";
        if (gasStationJerry.nameFirtTime) {
            gasStationJerry.nameFirtTime = false;
            gasStationJerry.jerryScored = true;
            iPeople++;
            "~Hi. Jerry's the name. Stuck inside this booth. Hopefully I can help you out.~";
        }
        "~Are you even listening? Jerry's the name.~";
  ];

  [ AnswerYesJerry;
        if (gasStationJerry.askForCar) "~Thanks. I think the effort is worth it. Plus, it makes the boss happy.~";
        if (gasStationJerry.askAboutCats) "~I doubt that.~";
        if (gasStationJerry.askAboutPlug) "~Good luck. I know my way around engines, and I was never able to get that one working.~";
        "~Did I ask you something? Forget it.~";
  ];

  [ AnswerNoJerry;
        if (gasStationJerry.askForCar) "~Like you have any taste.~";
        if (gasStationJerry.askAboutCats) "~I know. Creepy.~";
        if (gasStationJerry.askAboutPlug) "~I don't blame you. I've never gotten anywhere with that mower.~";
        print "~Don't be so negative. It's a beautiful ";
        if (SelfPlayer.morningTime) "morning.~";
        if (SelfPlayer.dayTime) "day.~";
        if (SelfPlayer.dayStart || SelfPlayer.eveningTime || SelfPlayer.preEvening) "evening.~";
        "night.~";
  ];
