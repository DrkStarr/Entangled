! Character Diamond
! 1: Ambitious - Wants To Model
! 2: Outgoing
! 3: Secret - She's Not A Punk, Doesn't Like Punk Music - Likes ABBA
! 4: Easily Offened - Short Temper
! 5: Sneaky - Sly - Coy
! 6: Comes from a devorced household. Lives with Mother who she doesn't like, and a step father that tries to abuse her

! ---------------------------------------------------------------------------- !
!       NANCY. 08/11/16
! Age: 19
!

  Object  -> alleyRentalNancy "teen"
    with  name 'nancy' 'punk' 'attendant' 'woman' 'girl' 'chick' 'teen' 'lady' 'mohawk' 'dyed' 'platinum' 'blonde' 'nails',
          describe [;
              rtrue;
          ],
          daemon [;
              ! Used to get Nancy to respond to asking about the city / response Yes/No
              if (self.askAboutCity) {
                  iAskCity++;
              }
              if (self.dontKillAskAboutCity) {
                  self.dontKillAskAboutCity = false;
              } else {
                  if (iAskCity > 1) {
                      iAskCity = 0;
                      self.askAboutCity = false;
                  }
              }

              if (self.askAboutBowling) {
                  iAskBowling++;
              }
              if (self.dontKillAskAboutBowling) {
                  self.dontKillAskAboutBowling = false;
              } else {
                  if (iAskBowling > 1) {
                      iAskBowling = 0;
                      self.askAboutBowling = false;
                  }
              }

              if (self.askIntroQuestion) {
                  iAskIntro++;
              }
              if (iAskIntro > 1) {
                  iAskIntro = 0;
                  self.askIntroQuestion = false;
              }

              if (self.triggerAskFriend) {
                  iAskFriend++;
              }
              if (iAskFriend > 1) {
                  iAskFriend = 0;
                  self.triggerAskFriend = false;
              }
          ],
          before [ w1;
              AskCreatureFor:
                  iNancyConversation++;
                  wn = consult_from;
                  w1 = NextWord();
                  switch (w1) {
                      'freshener', 'can', 'spray':
                          print "~You really need my freshener,~ she asks with ";
                          if (self.angry) "darts in her eyes.";
                          "a glare in her eyes.";
                      'name':
                          return AskForNameNancy();
                      'change', 'quarters', 'quarter':
                          "~I can only open the register for someone who's going to bowl. And I doubt
                          you're going to do that.~";
                  }
                  return NancyResponse();
              AskTo:
                  iNancyConversation++;
                  switch(second) {
                      t_bowl:
                          "~Can't you see I'm working here? And if I wasn't. I don't think I'd go out with you. Sorry.~";
                  }
                  return NancyResponse();
              Buy, Rent:
                  if (self.angry) "You think twice about pissing her off again.";
                  self.angry = true;
                  print "~What do you think I am? Some sort of tramp?~ the punk shouts, ~Get out of here before
                  I call the cops.~^^
                  Not wanting to piss her off anymore you step back into the entrance of the alley.^";
                  iNancyConversation = 0;
                  PlayerTo(bowlingAlley);
                  rtrue;
              Enter, Go:
                  "You're already here.";
              Examine:
                  "With a platinum-dyed mohawk, this girl sticks out. She looks like a model or
                  a rock star that shouldn't be working here. But she seems bored, tapping her
                  nails on the keypad of the register.";
              Kiss:
                  "~Watch it,~ she says pushing you back, ~I'm not into the poor.~";
              Talk:
                  print "[You can try ";
                  if (self.AskAboutCan) {
                      print "ASK ABOUT SHOES";
                  } else {
                      print "ASK ABOUT FRESHENER";
                  }
                  print " or ";
                  if (self.askCity) {
                      if (self.askNYC) {
                          print "ASK ABOUT MODELING";
                      } else {
                          print "ASK ABOUT NEW YORK";
                      }
                  } else {
                      print "ASK ABOUT CITY";
                  }
                  ". There are also lots of other things too.]";
              Hello:
                  if (self.askAboutBowling) self.dontKillAskAboutBowling = true;
                  self.askAboutBowling = true;
                  "~Are you really here to bowl?~ she asks, ~you don't look like the bowling type.~";
              Eat, Taste:
                  "What? Are you a cannibal? I know you're not that hungry.";
              WaveObject:
                  if (self.askAboutBowling) self.dontKillAskAboutBowling = true;
                  self.askAboutBowling = true;
                  "~Yes. I see you. Now, are you going to rent anything?~";
              Take:
                  "You know she's not an object?";
              Attack, Blow, Burn, Buy, Climb, Close, Cut, Dig, Drink, Eat, Empty, Enter, Exit, GetOff, Go, JumpOver, Kick, Kiss, Listen, LookUnder, Open:
                  "You can't do that. She's behind the counter.";
              Push, PushDir, Pull, Read, Remove, Rub, Search, Set, SetTo, SmellNoun, Squeeze, Swing, SwitchOn, SwitchOff, Take, Talk, Taste, Tie, Touch, Transfer, Turn, Unlock, Wave:
                  "You can't do that. She's behind the counter.";
          ],
          life [ w1;
              Answer:
                  switch(noun) {
                      t_hi: <<Hello self>>;
                      t_yes: return AnswerYesNancy();
                      t_no: return AnswerNoNancy();
                      t_good: "~Like. Glad to hear it.~";
                      t_bad: "~Gag me. Maybe tomorrow will be better.~";
                      t_sorry: "~Like. It'll pass.~";
                      t_thanks: "~For sure. I try my best.~";
                      default:
                          return (NancyResponse());
                  }
              Ask:
                  iNancyConversation++;
                  wn = consult_from;
                  w1 = NextWord();
                  switch (w1) {
                      'halloween', 'samhain':
                          "~Halloween can be fun. Last year I dressed up as a vampire. Everybody wanted me to bite them.~";
                      'candy':
                          "~I don't like candy. And I don't eat sugar. Who needs it anyway.~";
                      'amy', 'clerk', 'plain', 'jane':
                          "~Oh my God, like, what about her. Amy's as plain as they come. You know?
                          That's my worst fear. Becoming mediocre.~";
                      'bob', 'boss', 'owner':
                          "~What about Bob? He can be a real creep. He likes to come around here and hit on me.~";
                      'bum', 'ed', 'eddie':
                          "~Yeah, like, I'm not into the poor.~";
                      'city', 'town', 'sunnybrook':
                          if (self.askAboutCity) self.dontKillAskAboutCity = true;
                          self.askAboutCity = true;
                          print "~This town's so dull. Like, I'm looking to hit New York";
                          if (self.askCity) ".~";
                          self.askCity = true;
                          ". Once I get some more money.~";
                      'freshener', 'can', 'spray':
                          self.AskAboutCan = true;
                          "~Like. It's just some spray that I throw in the shoes when someone rents them.
                          I can't stand the smell.~";
                      'smell':
                          "~It's gross. Kind of reminds me of old people.~";
                      'customer', 'customers':
                          "~Oh my God, like, we get all types that come in here.~";
                      'me', 'self', 'yourself':
                          "~I don't know. What about you? I haven't seen ya' in here before.~";
                      'current', 'date', 'year':
                          "~Like. That's a strange question for sure.~";
                      'doorman':
                          "~The one that works over at Highland Towers? Like. Oh my God. He's the worst.
                          You think he'd recognize someone with so much talent. Loser.~";
                      'complex', 'high-rise', 'highrise', 'highland', 'towers', 'apartment', 'apartments':
                          "~They have parties over there. You know how it is. Rich people with money to blow.
                          But you can't get in. That doorman's a real pain.~";
                      'jerry', 'attendant':
                          "~Like. He's funny and all, but how motivated is he. Oh my God. I don't think he
                          ever plans to move on from the gas station. All I want to do it get out of this town.~";
                      'hell':
                          if (self.hellFirstTime) "~Oh my God. You don't have to beat me up about it.~";
                          self.hellFirstTime = true;
                          "~I don't mean anything by it, like, it's just something I use to break the ice.~";
                      'harry', 'old', 'guy':
                          "~You're talking about that old guy that likes to hang out at The Tavern. What
                          about him? I've seen him down there when I've had to speak to Nick. Keeps to himself.~";
                      'house', 'abandoned':
                          if (self.knowAboutHouse) "~Like. I have a little history there. But God. No one cares about that place.~";
                          self.knowAboutHouse = true;
                          "~You mean the old one behind here. Gosh. I haven't thought about that place
                          in years. Like, it's been a while.~";
                      'history':
                          "~God. Mind your own business.~";
                      'keypad', 'pad':
                          "~I like to mess around with it, you know, see if I can come up with something new.~";
                      'library':
                          "~What do you think I am? A bookworm? I don't have four eyes. Get out of here.~";
                      'bar':
                          "~People love to get hammered across the way. Then they come back here. I have
                          to deal with them. Always hitting on me. Gosh.~";
                      'school', 'schooling':
                          "~Like. I graduated last year from high school but spent the summer in
                          California. Meet a friend who's going to live with me in New York. You watch.
                          I'm going to be a model.~";
                      'california', 'cali', 'beach', 'la', 'los', 'angeles':
                          "~It was a blast out there last summer. Like. I love the beach and the sun, and all the people that hang out and mingle. It's not a dull dead-end like this town.~";
                      'friend':
                          if (self.askAboutFriend) {
                              if (self.answerFriendNo) "~What do you care? You don't even think I should go out there.~";
                              "~Yeah, she's really fun. Likes to party. I'm sure we're going to have a good time.~";
                          }
                          self.triggerAskFriend = true;
                          self.askAboutFriend = true;
                          "~Like. We met on the beach. She's real friendly. Was talking about getting out of LA. Going to New York. I think it's a great idea.~";
                      'college':
                          "~I have no reason to go to college. God. Like all those books. All that reading.
                          I'm getting out of this town. I'm going to be a model.~";
                      'post', 'office':
                          "~Yeah. I hate it. But I go over there to mail my friend in California.
                          It costs too much to call on the phone. Wouldn't it be nice if we could talk
                          for free.~";
                      'yard', 'junkyard', 'millers', 'miller', 'miller^s', 'miller?s':
                          "~I wouldn't go in there. And like that dog. Wow is he mean.~";
                      'dog', 'doberman':
                          "~Oh yeah. That dog over at Miller's yard. Is there anything meaner around here?
                          Kind of like the song, right?~";
                      'song':
                          "~You know: Bad, Bad Leroy Brown. Jim Croce at his best.~";
                      'the', 'tavern':
                          "~I go down there to see Nick. He's my boy. Gonna make it someday, I tell him.~";
                      'time', 'note', 'notes': "You better keep that information to yourself.";
                      'covid', 'bug', 'corona', 'coronavirus', 'virus': "You should keep that information to yourself.";
                      'kids':
                          "~Everybody comes and goes from here - especially kids. They can't get enough of that arcade machine.~";
                      'arcade', 'machine', 'game':
                          "~The kids seem to come here more to play that game than to bowl.  It's probably 'cause they were raised on cartoons.~";
                      'cartoon', 'cartoons':
                          "~You know, cartoons. Bugs Bunny, Daffy Duck. Kids stuff.~";
                      'mark', 'tom':
                          "~Can't say I know anybody by that name.~";
                      'name':
                          return AskForNameNancy();
                      'nancy', 'girl', 'herself', 'plan', 'plans', 'her', 'teen', 'woman', 'chick', 'lady':
                          "~Like. I'm gonna make it big in New York. You know. Modeling.
                          Gonna get an apartment with my friend from California. Like it's
                          going to be far out.~";
                      'nick', 'pretty', 'boy':
                          "~He's my type. He's going somewhere and so am I. Figure I have a better
                          chance at modeling or acting than in music.  But it will be nice to meet up
                          with him down the road.~";
                      'number', 'numbers':
                          if (self.askAboutNumber) "~Aren't you listening. Oh my god. Like it's 7734.~";
                          self.askAboutNumber = true;
                          "~You want to know the number? Rad. It's 7734. Like. It works best on my register.~";
                      'newyork', 'new', 'nyc':
                          self.askNYC = true;
                          self.triggerAskFriend = true;
                          "~I've always wanted to live in New York and I'm sure I can model there. My friend from California
                          wants to move out there too, so we're going to get a place together.~";
                      'music':
                          if (self.askAboutPunkMusic) "~Like. My favorite band is ABBA, but no one around here likes them.~";
                          self.askAboutPunkMusic = true;
                          "~You know, I'm not really into punk music. I just like the look. I stand out in a town like this.~";
                      'abba':
                          "~Dancing Queen is my favorite. Like for sure. But Take A Chance On Me has a good hook too.~";
                      'punk':
                          if (self.askAboutPunkMusic) "~Like I said. I'm not really a punk.~";
                          self.askAboutPunkMusic = true;
                          "~You know, I'm not really into punk music. I just like the look. I stand out in a town like this.~";
                      'mabel':
                          "~Mabel? Gosh, yeah. She works over at the pharmacy. Has a sad life. Shoot
                          me if I end up like that. No really, stop me before I become bitter and old.~";
                      'model', 'modeling', 'modelling':
                          "~Everybody says I can do it. So why not? Plus I get to live in New York,
                          not some small town in the sticks. I'll be out of here soon enough.~";
                      'phil', 'phill', 'bartender':
                          "~Gross. What about him. He works across the way in the bar. I don't talk to him much.~";
                      'rental', 'rentals', 'rent', 'renting':
                          if (alleyRentalShoes.shoesSecondTime) "~If you got the money then put it on the counter. $1.00 an hour for shoe rental. 50 cents a game. God.~";
                          if (alleyRentalShoes.shoesFirstTime) {
                              alleyRentalShoes.shoesSecondTime = true;
                              "~So. It's a buck fifty an hour for shoe rental and the game. Like. When you get it come on back.~";
                          }
                          if (self.askAboutBowling) self.dontKillAskAboutBowling = true;
                          self.askAboutBowling = true;
                          alleyRentalShoes.shoesFirstTime = true;
                          "~Like. Are you going to bowl? Cause it's not free you know.~";
                      'sam':
                          print "~Uh. Like. I don't even know Sam. God.";
                          return AskMultiAboutSam();
                      'gas', 'station':
                          "~Jerry works over there. He's funny. Makes me laugh whenever I see him.
                          But is he ever going to move on?~";
                      'convenience', 'drug', 'store':
                          "~I stay out of there. Not only is it dirty, but Plain Jane works over there.~";
                      'pharmacy':
                          "~Never get over there. I stay away from the drug store. I don't want to be seen
                          around that clerk.~";
                      'judy':
                          "~Like. I know a Judy at school, but no one that works here.~";
                      'art', 'gallery':
                          "~I've been there, bought a crystal necklace once. But the thing fell apart. It was cheap.
                          I tried to get my money back, but the curator wouldn't hear of it.~";
                      'sarah', 'curator', 'hippie':
                          "~What? The woman that works in the gallery? She's a hippy from the '60s.
                          Has some crazy ideas.~";
                      'scientist':
                          "~Like. I've never heard of him.~";
                      'shoe', 'shoes':
                          "~Oh, my God. Like. I've learned to hate shoes. Having to keep them clean, unsticking the laces, even prying off the gum. Gross.~";
                      'madame', 'sorra', 'gypsy', 'fortune-teller', 'fortune', 'teller':
                          "~She's a creepy old witch for sure.  My pa says she's been around since he
                          was a kid. If you knew how she stayed alive, it would make your skin crawl.~";
                      'curse', 'cursed':
                          "~Like. I don't know. It's just a feeling. I'm sure she would curse it to protect it.~";
                      'work', 'job', 'shop', 'place', 'bowling', 'alley':
                          "~Oh, you know, it's a pain working here. But it's giving me the money for New York.~";
                      'trailer', 'park':
                          "~You look like someone who lives in that trailer park.
                          You have that poor aura around you.~";
                      'yukypah', 'heef', 'statue':
                          "~I know we're supposed to respect him and all. But really?
                          He's a thousand years old and dead. What did he even do?~";
                      'bus':
                          "~Like. Gross. That bus only goes to Melville. Why would I want to go there?~";
                      'melville', 'melvill':
                          "~The scummiest people come from Melville. You can see them a mile away when they
                          walk through that door.~";
                      'change', 'quarters', 'quarter':
                          "~I can only open the register for someone who's going to bowl. And I doubt
                          you're going to do that.~";
                      'plug', 'spark', 'sparkplug', 'fuse':
                          "~Like. What would I be doing with a spark plug? I'm not a mechanic. God. That's Jerry's thing.
                          If you need him, he's over at the gas station.~";
                      'necklace', 'necklaces', 'something':
                          "~I bought one of those necklaces from the gallery. It fell apart a week
                          later and I broke the crystal. I tried to bring it back, but she said it was my fault.~";
                      'shard', 'crystal', 'crystals':
                          "~The curator over at the gallery usually has that sort of thing. But God.
                          The last time I bought something over there it just fell apart.~";
                      'vacuum', 'tube', 'tubes':
                          "~Like. Oh my God. Do I look like a hardware store? Try Phil. The bartender across the way. He seems handy.~";
                      'register':
                          "~Yeah. With these new digital registers you can mess around with the numbers. Spell out things for the fun of it.~";
                      'kiss', 'kissing':
                          "~I don't kiss and tell.~";
                      'him', 'himself', 'her', 'herself', 'them':
                          "At the moment, even the simplest questions are confusing.";
                      default:
                          return (NancyResponse());
                  }
              Tell:
                  wn = consult_from;
                  w1 = NextWord();
                  switch(w1) {
                      'hi', 'hello', 'hola', 'greetings':
                          <<Hello self>>;
                      'yes', 'please', 'ok': return AnswerYesNancy();
                      'no': return AnswerNoNancy();
                      'good': "~Like. Glad to hear it.~";
                      'bad': "~Gag me. Maybe tomorrow will be better.~";
                      'sorry': "~Like. It'll pass.~";
                      'time', 'machine', 'note', 'notes', 'house', 'abandoned', 'date', 'year':
                          "You better keep that information to yourself.";
                      'covid', 'bug', 'corona', 'coronavirus', 'virus': "You should keep that information to yourself.";
                      'him', 'himself', 'her', 'herself', 'them':
                          "At the moment, even the simplest statements are confusing.";
                      'thanks', 'thank': "~For sure. I try my best.~";
                      default: "~Like. I don't know. Got anything else going on?~";
                  }
          ],
          orders [;
              Hello:
                  <<Hello self>>;
              Give:
                  if (noun == alleyRentalFreshnes) {
                      print "~Like. You really need my freshener,~ she asks with ";
                      if (self.angry) "darts in her eyes.";
                      "a glare in her eyes.";
                  }
                  "~Like, you sure you really need that.~";
              Strong: "The punk ignores you.";
          ],
          angry false,
          nameFirstTime false,
          hellFirstTime false,
          askCity false,
          askAboutCity false,
          dontKillAskAboutCity false,
          cityAnswerNo false,
          cityAnswerYes false,
          AskAboutCan false,
          askNYC false,
          knowAboutHouse false,
          askAboutPunkMusic false,
          askAboutBowling false,
          dontKillAskAboutBowling false,
          askIntroQuestion false,
          askAboutNumber false,
          askAboutFriend false,
          triggerAskFriend false,
          answerFriendNo false,
    has   animate female concealed;

  [ NancyResponse;
        if (iNancyConversation > 5) {
            iNancyConversation = 0;
            "~Oh my God. Are you going to talk all night, 'cause? Like. I thought you were going to rent something.~";
        }
        if (iNancyConversation > 3) "~You know. Like. Does that really matter?~";
        "~Yeah. Like. I'm not sure about that one.~";
  ];

  [ AskForNameNancy;
        if (alleyRentalNancy.angry) "~No. Go insult somebody else.~";
        SelfPlayer.knowNancy = true;
        if (alleyRentalNancy.nameFirstTime) "~Gag me. I told you once. I'm not going to tell you again.~";
        alleyRentalNancy.nameFirstTime = true;
        iPeople++;
        "~Oh my God. You want to know too? Nancy. If you must know.~";
  ];

  [ AnswerYesNancy;
        if (alleyRentalNancy.askAboutCity) {
            if (alleyRentalNancy.cityAnswerYes) "~Oh my God. I can't wait to finally make it out of here.~";
            if (alleyRentalNancy.cityAnswerNo) "~Like. Do you really see it my way or are you just full of it?~";
            alleyRentalNancy.cityAnswerYes = true;
            "~Oh my God. Thanks. You know, like, not too many people see it my way around here. They all seem to want to hold me back.~";
        }
        if (alleyRentalNancy.triggerAskFriend) "~I know. Right? She's going to make for a great roommate. I'm sure.~";
        if (alleyRentalNancy.askIntroQuestion) "~Well, aren't you a know-it-all then.~";
        if (alleyRentalNancy.askAboutBowling) "~Then put down some cash. It's a buck and a half to get started.~";
        "~Like. For sure.~";
  ];

  [ AnswerNoNancy;
        if (alleyRentalNancy.askAboutCity) {
            if (alleyRentalNancy.cityAnswerNo) "~Oh my God. You're like everybody else around here. But, like, none of you are going to stop me.~";
            if (alleyRentalNancy.cityAnswerYes) "~Oh my God. Change your mind a lot?~";
            alleyRentalNancy.cityAnswerNo = true;
            "~Oh my God. Like. What would you know about staying in this town?
            I've lived here too long. I'm going to make something of myself. God.~";
        }
        if (alleyRentalNancy.triggerAskFriend) {
            alleyRentalNancy.answerFriendNo = true;
            "~Like. Oh my God. What would you know? Nothing is going to happen in this town.~";
        }
        if (alleyRentalNancy.askIntroQuestion) "~Yeah. It's really neat. A friend of mine showed me on a calculator. The number works here too.~";
        if (alleyRentalNancy.askAboutBowling) "~I'm always right. I know you're not here to bowl.~";
        "~Like. Don't be down.~";
  ];
