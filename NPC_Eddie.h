! Eddie drops G in ING.

! Character Diamond
! 1: Ruggeged / Struggling
! 2: Hummbel
! 3: Has A Dry Wit
! 4: Addict - Alcohol
! 5: Happy Inside?

! ---------------------------------------------------------------------------- !
!       EDDIE. 01/13/18
!
! Age: 42

  Object  smallParkEddie "bum"
    with  name 'middle' 'aged' 'man' 'middle-aged' 'guy' 'ed' 'eddie' 'dude' 'bum' 'rough' 'rough-looking',
          describe [;
              rtrue;
          ],
          daemon [;
              if (self.askHaveAny) {
                  iHaveAny++;
              }
              if (self.dontKillAskHaveAny) {
                  self.dontKillAskHaveAny = false;
              } else {
                  if (iHaveAny > 1) {
                      iHaveAny = 0;
                      self.askHaveAny = false;
                  }
              }

              if (self.askExtraCash) {
                  iExtraCash++;
              }
              if (self.dontKillAskExtraCash) {
                  self.dontKillAskExtraCash = false;
              } else {
                  if (iExtraCash > 1) {
                      iExtraCash = 0;
                      self.askExtraCash = false;
                  }
              }
          ],
          before [ w1;
              AskCreatureFor:
                  wn = consult_from;
                  w1 = NextWord();
                  switch (w1) {
                      'drink', 'drinks', 'bottle', 'whiskey', 'scotch', 'vodka', 'beer':
                          if (self.askHaveAny) self.dontKillAskHaveAny = true;
                          self.askHaveAny = true;
                          "~Do you have any? It's been a while.~";
                      'cigarette', 'cigarettes', 'cig', 'cigs', 'fag', 'fags', 'smokes':
                          if (self.askHaveAny) self.dontKillAskHaveAny = true;
                          self.askHaveAny = true;
                          "~I'd love a smoke. You got one?~";
                      'name':
                          return AskForNameEddie();
                      'change', 'quarters', 'quarter':
                          "~I don't have any. I was hopin' you had some. You know, some to spare.~";
                  }
                  return EddieResponse();
              Examine:
                  "White strands lace his overgrown beard. Fingernails dirty, clothes are worn in,
                  he tries to hide the fact that he hasn't washed in a month. He watches you with
                  little else to do.";
              Search, Climb:
                  "I don't think he would care for that.";
              Talk:
                  print "[You can try ";
                        if (self.askHouse) {
                            if (self.askStorm) {
                                print "ASK ABOUT STORM"; ! STORM
                            } else {
                                print "ASK ABOUT HOUSE"; ! HOUSE
                            }
                        } else {
                            print "ASK ABOUT PARK";  ! PARK
                        }
                        print " or ";
                        if (self.askAboutWork) {
                            print "ASK ABOUT MELVILLE";
                        } else {
                            print "ASK ABOUT WORK";
                        }
                        ". There are also lots of other things too.]";
              Hello:
                  if (self.sayHello) "The guy picks at his fingernails, ignoring you.";
                  self.sayHello = true;
                  "The guy picks at his fingernails for a minute, then looks up, ~Hey.~";
              WaveObject:
                  if (self.askHaveAny) self.dontKillAskHaveAny = true;
                  self.askHaveAny = true;
                  "~How you doin'? You wouldn't have anythin' to drink, would you?~";
              Kiss, Rub, Touch, Pet, SmellNoun:
                  "Try as you might, you can't bring yourself to do it.";
              Eat, Taste:
                  "What? Are you a cannibal? I know you're not that hungry.";
              Attack, Kick, Push, Pull:
                  "Life has knocked this guy down. There's no need to help.";
              Take:
                  "You know he's not an object?";
          ],
          life [ w1 w2;
              Answer:
                  switch(noun) {
                      t_hi: <<Hello self>>;
                          t_yes: return AnswerYesEddie();
                          t_no: return AnswerNoEddie();
                          t_good: "~Must be nice.~";
                          t_bad: "~It's always like that.~";
                          t_sorry: if (self.askExtraCash) "~I can always hope,~ he says, as a slight smile creases his lips.";
                                   if (self.askHaveAny) "~I know. It sucks.~";
                                   "~Aren't we all?~";
                          t_thanks: "He grumbles to himself, probably cursing you.";
                          default:
                              return EddieResponse();
                      }
              Ask:
                  wn = consult_from;
                  w1 = NextWord();
                  w2 = NextWord();
                  if (w1 == 'old' ) {
                      if (w2 == 'guy' ) {
                          return EddieHarryResponse();
                      }
                  }
                  switch(w1) {
                      'halloween', 'samhain':
                          "~Things get crazy around Halloween. Especially when the full moon is out.~";
                      'candy':
                          "~I don't really have a sweet tooth. But beggars can't be choosers, right?~";
                      'bowling', 'alley':
                          "~I've tried to go in there, but Bob is a pain. Rides my ass when he sees me. Doesn't want me scaring away the customers.~";
                      'bar', 'the', 'tavern', 'convenience', 'drug', 'store','pharmacy':
                          "~They're usually lookin' for payin' customers. That's not my gig.~";
                      'city', 'town', 'sunnybrook':
                          self.askAboutCity = true;
                          "~The people are better than most. That's why I've stayed here.
                          Some of them have helped out over time, and no one gives me any
                          trouble with sleepin' in the park.~";
                      'current', 'date', 'year':
                          "~Yeah. Times are hard. Ever since the '70s with inflation it's been
                          near impossible to make it out here.~";
                      'drink', 'drinks', 'bottle', 'whiskey', 'scotch', 'vodka', 'beer', 'cigarette', 'cigarettes', 'cig', 'cigs', 'fag', 'fags', 'smokes', 'flask', 'alcohol', 'booze':
                          if (self.askHaveAny) self.dontKillAskHaveAny = true;
                          self.askHaveAny = true;
                          "~Do you have any? It's been a while.~";
                      'dollar', 'buck', 'bill', 'cash':
                          if (dollarBill.dollarScore) {
                              print "~Too bad you showed up. I thought I was about to have a drink";
                              if (dollarBill in player || dollarBill in clothes) ". You know I still can.~";
                              ".~";
                          }
                          if (self.askExtraCash) self.dontKillAskExtraCash = true;
                          self.askExtraCash = true;
                          "~Have any extra cash on you friend?~";
                      'junk', 'food', 'burger', 'burgers', 'meal', 'chocolate':
                          "~I could go for anythin'. Whatever it is, fork it over.~";
                      'beef', 'jerky', 'plastic', 'meat', 'pack', 'package':
                          "~Jerky has always torn me up a bit. I don't know what it is.~";
                      'house', 'abandoned':
                          if (self.askHouseAgain) "~That's it. I crash out there sometimes. But I don't know if I'll go back.~";
                          if (self.askHouse) {
                              self.askStorm = true;
                              self.askHouseAgain = true;
                              "~I did see somethin' strange happen earlier tonight. Like a lightning
                              storm comin' from the basement. I wanted to get inside to see if I had
                              any booze left, but came back here instead of dealin' with that craziness.~";
                          }
                          self.askHouse = true;
                          "~You mean the abandoned one behind the bowlin' alley?
                          Sometimes I go over there and sleep in the livin' room. No one bothers me about it.~";
                      'time', 'machine', 'note', 'notes':
                          "You better keep that information to yourself.";
                      'covid', 'bug', 'corona', 'coronavirus', 'virus': "You should keep that information to yourself.";
                      'music':
                          "~Can't say I'm so inclined. Was never really that fortunate when growin' up.~";
                      'name':
                          return AskForNameEddie();
                      'statue':
                          if (crystalCat in player)
                              "~Sarah told me that she had to stop sellin' necklaces and started
                              sellin' statues like that. I'm glad to see she's startin' to move them.~";
                          "~They say it's of Yukypah Heef. Some founder. I've never heard of him.
                          So I piss on him when I have the chance.~";
                      'yukypah', 'heef':
                          "~He's the founder, or so people say. But how far does that go back?
                          I mean, when was this town put on paper?~";
                      'lightning', 'storm', 'basement':
                          if (self.askAboutStorm)
                              "~It's hard to believe and crazy too. But you see some
                              strange stuff livin' on the street. I can tell you that.~";
                          self.askAboutStorm = true;
                          "~Yeah, it was far out, as the kids would say. Bolts of lighting comin'
                          from underneath the place. Like an electrical storm in the basement. I
                          know it makes no sense.~";
                      'work', 'job', 'shop', 'place':
                          if (self.askAboutWork) "~Why do you care?~";
                          self.askAboutWork = true;
                          self.askAboutMelville = true;
                          "~Why do you care? Hm. No mind. I used to work for a local factory in Melville. But then,
                          around 1960 or so, I ended up reading 'On The Road.' I quit that gig and found my path.~";
                      'path':
                          "~We all have one. I ended up on the street. But I've seen a lot from down here. Things you people wouldn't believe.~";
                      'book', 'on', 'road':
                          "~That book changed my life and the whole generation. Once we found out that
                          there was a world out there we could explore, it didn't take long for us to
                          drop out and tune into it. I never went back.~";
                      'inflation':
                          "~Yeah, the price of everythin' keeps goin' up and up. Once gas broke a dollar
                          a gallon about five years back, everyone has been cautious with their money.~";
                      'library':
                          "~Even though they're open to the public, they don't like me hangin' around.
                          They're always givin' me crap when I go over there. So I don't.~";
                      'school', 'schooling':
                          "~I graduated high school. Even had a steady job for a while. Then 'On The Road'
                          came out. Found it when I was 22. Changed my whole life. I found the road.~";
                      'college':
                          "~Never went to college. Didn't even try. Couldn't afford it.~";
                      'post', 'office':
                          "~Don't have much to say about the post office. I have no reason to go over there.~";
                      'gas', 'station':
                          "~Yeah. I go over there once in a while to use the bathroom. One of the
                          attendants is pretty cool.~";
                      'yard', 'junkyard', 'millers', 'miller', 'miller^s', 'miller?s':
                          "~What about the junkyard? I'd stay away. That dog is nothin' to mess with.~";
                      'dog', 'doberman':
                          print "~That dog over at the junkyard is a Doberman. At times I can hear him bark
                          all the way over here";
                          if (rustyGate.dogBarking) ". Listen. You can hear him now.~";
                          ".~";
                      'bus':
                          "~I've tried to sleep over there. It's uncomfortable. The house
                          behind the alley is the best place to get some rest. But I don't
                          know if I'd ever go over there again.~";
                      'melville', 'melvill':
                          print "~A couple of people said I should make that place my home. But Melville's a dirty town. I don't want to live there. ";
                          if (self.askAboutMelville) "And that factory was hell to work in.~";
                          self.askAboutMelville = true;
                          "I used to work in a dingy factory. Man, that was hell.~";
                      'park':
                          self.askHouse = true;
                          "~Stayin' out here doesn't work so well on rainy nights, so I'll go over
                          to the abandoned house behind the bowlin' alley when it's like that. But
                          now I'm not sure where I'll go.~";
                      'bum', 'ed', 'eddie', 'guy', 'him', 'himself', 'man', 'dude':
                          if (self.askAboutSelfTwice) "~I already told you. My life took a wrong turn.~";
                          if (self.askAboutSelf) {
                              self.askAboutSelfTwice = true;
                              "~Yeah. After I quit my job, I just started hittin' the bottle.
                              Not the best choice, but what is?~";
                          }
                          self.askAboutSelf = true;
                          "~I don't know, my life kind of took a wrong turn. What do you want me to say?~";
                      'kids':
                          "~I see kids out here at all hours. It makes me think: where are the parents. At least they don't bother me.~";
                      'scientist':
                          "~You know I see a lot of people out here, but no one like that.~";
                      'sam':
                          print "~Never heard of him.";
                          return AskMultiAboutSam();
                      'judy':
                          "~I don't think I've seen anybody like that.~";
                      'bob':
                          "~That guy doesn't like me. Runs me out of the alley every time I go in. And if someone in this town could help me out, he could.~";
                      'mabel':
                          "~What? The old lady that works over at the pharmacy? She's older than me
                          and wouldn't help a fly. I try to stay away from her.~";
                      'mark', 'tom':
                          "~Not sure. But I don't think anybody like that lives around here.~";
                      'amy', 'clerk', 'girl':
                          "~The girl that works the drug store. What about her?~";
                      'doorman':
                          "~That guy is somethin' else. I'd just stay away from him.~";
                      'complex', 'high-rise', 'highrise', 'highland', 'towers', 'apartment', 'apartments':
                          "~You got to be rich to live over there, but why would you? That doorman is a pain.~";
                      'jerry', 'attendant':
                          "~What? The kid over at the garage? He's cool. Lets me use the
                          bathroom now and then. I don't think he's supposed to.~";
                      'harry':
                          return EddieHarryResponse();
                      'phil', 'phill':
                          "~Phil? The bartender from the alley? I've seen him around town.
                          Keeps to himself, mostly, and never helped me out.~";
                      'nancy', 'punk':
                          "~You mean that fox over at the bowlin' alley?
                          She's a little young for me. And I doubt she'd
                          share a bottle out here.~";
                      'nick':
                          "~That cat's cool. Plays a mean ax. When the band plays live, you can hear
                          them out here. If someone can make it out of this town, it's him.~";
                      'art', 'gallery':
                          "~I've never been inside the gallery but the curator helps me out when she can.~";
                      'sarah', 'curator', 'hippie':
                          "~She never seems happy when I see her, but she's helped me out now
                          and then. A kind soul. But tormented in her own way.~";
                      'madame', 'sorra', 'gypsy', 'fortune-teller', 'fortune', 'teller':
                          "~That old fortune-teller? She creeps me out. People think she never leaves her place,
                          but I've seen her in the dead of night. Strange things wander around that one.~";
                      'change', 'quarters', 'quarter':
                          "~I don't have any. I was hopin' you had some. You know, some to spare.~";
                      'plug', 'spark', 'sparkplug', 'fuse':
                          "~You're lookin' for a spark plug? Maybe you could find one over at the gas station.
                          The attendant over there has never given me the runaround.~";
                      'shard', 'crystal', 'crystals':
                          "~I'm sure Sarah might have one. The curator over at the gallery. She's kind-hearted
                          and I'm sure she'd try to help you out. Has always been nice to me.~";
                      'vacuum', 'tube', 'tubes':
                          print "~I don't have one right now,~ he says ";
                          if (self.askForTube) {
                              self.askForTube = false;
                              print "patting himself down";
                          } else {
                              print "checking again";
                          }
                          ", ~but if I find one, can you trade me some booze for it?~";
                      'factory':
                          "~Long hours, low pay, and a boss that would ride my ass. Yeah. I was happy to quit that job.~";
                      'scarf', 'babushka', 'headscarf', 'stole', 'muffler', 'tippet', 'kerchief', 'bandanna':
                          "~Oh. You're lookin' for a scarf. Might have one if you had some booze.
                          You know how it is. I'm a little dry tonight.~";
                      'bench', 'benches':
                          "~Yeah. They're hard to sleep on, but I guess it's all I got. What, with the house and all.~";
                      'me', 'self', 'yourself':
                          "~You look new to the street. Haven't seen you out here before.~";
                      'ufo', 'ufos':
                          "~You believe in UFOs? You've been watchin' too much 'In Search Of.' Leonard Nimoy has a screw loose.~";
                      'streets', 'street':
                          "~It's hard out here. You never have a good meal, but at least I'm not a slave to the corps.~";
                      'corps', 'corp':
                          "~You know, the corporations. Everybody is a slave to them. They're tearin' this country apart.~";
                      'slave', 'slaves':
                          "~You see them goin' off to work every day. It's a sad sight, really.~";
                      'things':
                          "~Like I said, you wouldn't believe me.~";
                      'being', 'dry':
                          "~God. It feels like I haven't had a drink in a week. Dry is an understatement. I really could use some.~";
                      'him', 'himself', 'her', 'herself', 'them':
                          "At the moment, even the simplest questions are confusing.";
                      default:
                          return (EddieResponse());
                  }
              Tell:
                  wn = consult_from;
                  w1 = NextWord();
                  switch(w1) {
                      'hi', 'hello', 'hola', 'greetings':
                          <<Hello self>>;
                      'yes', 'please', 'ok':
                          return AnswerYesEddie();
                      'no':
                          return AnswerNoEddie();
                      'good':
                          "~Must be nice.~";
                      'bad':
                          "~It's always like that.~";
                      'sorry':
                          if (self.askExtraCash) "~I can always hope,~ he says, as a slight smile creases his lips.";
                          if (self.askHaveAny) "~I know. It sucks.~";
                          "~Aren't we all?~";
                      'time', 'machine', 'note', 'notes', 'house', 'abandoned', 'date', 'year':
                          "You better keep that information to yourself.";
                      'covid', 'bug', 'corona', 'coronavirus', 'virus': "You should keep that information to yourself.";
                      'amy':
                          if (self.amyTold) {
                              if (self.harassHim) "There's no reason to harass him over it anymore.";
                              self.harassHim = true;
                              "You tell him that you know that he's spying on Amy.^
                              ^~I'm not watchin' her. I watch everybody. What else is there
                              to do on the street? I'll have to talk to her and straighten it out. Thanks.~";
                          }
                          "~Don't have much to say about her.~";
                      'him', 'himself', 'her', 'herself', 'them':
                          "At the moment, even the simplest statements are confusing.";
                      'thank', 'thanks':
                          "He grumbles to himself, probably cursing you.";
                      default:
                          "~I don't know about that. Keep it simple.~";
                  }
          ],
          orders [;
              Hello:
                  <<Hello self>>;
              Give:

              Open:

              Strong: "The bum ignores you.";
          ],
          eddieScored false,
          askHaveAny false,
          sayHello false,
          dontKillAskHaveAny false,
          nameFirstTime false,
          amyTold false,
          askAboutSelf false,
          askAboutSelfTwice false,
          askAboutWork false,
          askAboutCity false,
          askHouse false,
          askHouseAgain false,
          askAboutPark false,
          askAboutStorm false,
          gaveBumFlask false,
          askForTube true,
          harassHim false,
          askAboutMelville false,
          askStorm false,
          askExtraCash false,
          dontKillAskExtraCash false,
     has  animate male concealed;

  [ EddieResponse;
        "~Hmm. I don't get it.~";
  ];

  [ EddieHarryResponse;
        "~You mean that old guy, the one over at The Tavern? He's stingy, to say the least.
        I had a run-in with him once. Now I stay out of his way.~";
  ];

  [ AskForNameEddie;
        SelfPlayer.knowEddie = true;
        if (smallParkEddie.nameFirstTime) "~People never ask, now you're pesterin' me? Find somebody else.~";
        smallParkEddie.nameFirstTime = true;
        smallParkEddie.eddieScored = true;
        iPeople++;
        "~Name's Eddie. Not too many people ask, you know.~";
  ];

  [ AnswerYesEddie;
        if (smallParkEddie.askExtraCash) "~Maybe you wouldn't mind parting with some of it.~";
        if (smallParkEddie.askHaveAny) "~Way to hoard it.~";
        "~Always so happy?~";
  ];

  [ AnswerNoEddie;
        if (smallParkEddie.askExtraCash) "~I can always hope,~ he says, as a slight smile creases his lips.";
        if (smallParkEddie.askHaveAny) "~Damn. I could use some.~";
        "~I don't want to hear it.~";
  ];
