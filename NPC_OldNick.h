! Character Diamond
! 1: Ambitious - Keep Shop Running - Keep A Roof Over His Head
! 2: Cocky
! 3: Quicky Wit - Works As A Bartender
! 4: Dishonest - Brags

! bartender - bragging:
! When he was a bartender, everynight there was a new band in the place.
! He would play with them at the end of the night, sharpening his skills.
! People would buy him drinks afterwards.

! Player: No

! Are you calling me a lier?

! ---------------------------------------------------------------------------- !
!       OLD NICK. 06/03/19
!
! Born: 1957
! Age: 63

  Object  -> tattooShopNick "biker"
    with  name 'nick' 'biker' 'dude' 'man' 'guy' 'artist',
          describe [;
              rtrue;
          ],
          daemon [;
              ! Used if the player tells about "Eviction"
              if (self.tellAboutEviction) {
                  iTellNickEvict++;
              }
              if (iTellNickEvict > 1) {
                  iTellNickEvict = 0;
                  self.tellAboutEviction = false;
              }

              ! Used to get Nick to respond about clothing / response Yes/No
              if (self.askNickClothes) {
                  iAskClothes++;
              }
              if (self.dontKillAskNickClothes) {
                  self.dontKillAskNickClothes = false;
              } else {
                  if (iAskClothes > 1) {
                      iAskClothes = 0;
                      self.askNickClothes = false;
                  }
              }
          ],
          before [ w1;
              AskCreatureFor:
                  wn = consult_from;
                  w1 = NextWord();
                  switch (w1) {
                      'name':
                          return AskForNameOldNick();
                      'tattoo', 'tatoo', 'tattoos', 'tatoos', 'tattoing':
                          return AskBikerForTattoo();
                      'rose':
                          "~If you really want that, show me 50 bucks.~";
                  }
                  return OldNickResponse();
              Examine:
                  if (self.lookingUp) {
                      self.lookingUp = false;
                      "The biker sits in the corner, turning back to his magazine. He wears his leather
                      vest from back in the day, colors and all, even though he's not with the club anymore.";
                  }
                  "The biker sits in the corner, looking over a tattoo magazine. He wears his leather
                  vest from back in the day, colors and all, even though he's not with the club anymore.";
              Kiss:
                  "~When I was younger, people would hit on me all the time. Now I'm a little too old for that.~";
              Talk:
                  print "[You can try ";
                  if (self.askAboutTattoos) {
                      if (self.askAboutClub) {
                          print "ASK ABOUT SHOP";
                      } else {
                          print "ASK ABOUT CLUB";
                      }
                  } else {
                      print "ASK ABOUT TATTOOS"; ! He started out doing tattoos for his club.
                  }
                  print " or ";
                  if (self.askAboutMusic) {
                      if (self.askAboutLA) {
                          print "ASK ABOUT GUITAR";
                      } else {
                          print "ASK ABOUT LOS ANGELES";
                      }
                  } else {
                      print "ASK ABOUT MUSIC";
                  }
                  ". There are also lots of other things too.]";
              Hello:
                  "~How are you doing tonight?~";
              Eat, Taste:
                  "What? Are you a cannibal? I know you're not that hungry.";
              Pull, Push, PushDir, Kick, Rub, Touch, Pet, SmellNoun:
                  "That would be dumb and probably start a fight.";
              WaveObject:
                  "~You trying to fly or something? You look foolish,~ he says, turning back to his magazine.";
              Take:
                  "You know he's not an object?";
          ],
          life [ w1;
              Answer:
                  switch(noun) {
                      t_hi: <<Hello self>>;
                      t_yes: return AnswerYesOldNick();
                      t_no: return AnswerNoOldNick();
                      t_good: "~Always glad to hear.~";
                      t_bad: "~Times are tough. Sorry to hear.~";
                      t_thanks:
                          if (self.askAboutTom) "~Glad I could help.~";
                          "~If you say so.~";
                      t_sorry: "~Why be like that. Keep a stiff upper lip.~";
                      t_goodbye: "~Have a good night.~";
                      default:
                          return OldNickResponse();
                  }
              Ask:
                  wn = consult_from;
                  w1 = NextWord();
                  switch (w1) {
                      'halloween', 'samhain':
                          "~It's around the corner. But I don't have to worry about kids knocking on the door. So I always get candy for myself.~";
                      'candy':
                          "~Reese's is my favorite. It's all I get.~";
                      'bowling', 'alley':
                          "~I don't bowl and I gave up drinking a long time ago.~";
                      'amy', 'clerk':
                          "~Amy? She's worked at that convenience store for as long as I've known her.
                          When I left for Los Angeles, she went to college or something. When I came
                          back, she was still there. Guess it didn't work out for her.~";
                      'bar', 'the', 'tavern':
                          print "~They closed that place almost a year ago. It's hard running a business in this town now. ";
                          if (self.askAboutTavern) "Things were better in the 90s, but then wasn't everything better in the 90s?~";
                          self.askAboutTavern = true;
                          "Did you know that I used to work there? I was young, and before I went out to L.A., that was ages ago.~";
                      'art':
                          "~You have to be at least a good artist to ink people. Have to be able to draw what you put on them.
                          Or at least trace it. Yeah. I've been doing this longer than I care to think.~";
                      'city', 'town', 'sunnybrook':
                          "~Sunnybrook has become home. I grew up here but left. You know how it
                          is. That gypsy spirit. But being out there can be rough. I got lucky though.
                          Brought back enough to start this shop. Been here ever since.~";
                      'current', 'date', 'year':
                          "~Times are getting crazy. Right? Didn't use to be like this. Now it feels
                          like the inmates are running the asylum.~";
                      'doorman':
                          "~That guy that works over at the Towers? That place is a dump. I don't even know
                          why they keep someone like that around.~";
                      'complex', 'high-rise', 'highrise', 'highland', 'towers', 'apartment', 'apartments':
                          if (self.askAboutComplex) "~Like I said. That property will never be the same.~";
                          self.askAboutComplex = true;
                          "~Highland Towers? That place went downhill. The owner took all the money he was making and spent it on a mistress.
                          He never maintained it. Then when he went through the divorce, he had to sell it. The property has never been the same.
                          I'm surprised they still have a doorman.~";
                      'guitar', 'gear', 'ax', 'axe':
                          "~I use to have a '58 Les Paul Sunburst. That was a mean ax. But I sold it when I
                          opened this shop. Sold all my gear. It was a fair trade. I made a living from this
                          and it keeps a roof over my head.~";
                      'past':
                          "~I've had a colorful one. Maybe I'll tell you about it one day.~";
                      'los', 'angeles', 'la':
                          self.askAboutLA = true;
                          "~Yeah, I used to live out there. Some crazy times. I played guitar for a few bands,
                          but wrote a hit with this one guy. Axl. Made pay dirt there. He went off and made
                          it big. I took the money and ran.~";
                      'hit', 'song':
                          "~The song was 'Welcome To The Jungle.' Slash put in the beginning, but I wrote the main verse.
                          Axl never gave me credit, but I still got paid.~";
                      'axl':
                          "~The guy made a name for himself. I'll give him that. But that whole industry is cutthroat.
                          I'm glad I got out.~";
                      'library':
                          "~I'm an artist, used to be a musician, but I was never a reader. I don't go there.~";
                      'music', 'tunes', 'heavy', 'metal', 'rock':
                          self.askAboutMusic = true;
                          "~You like it? It's some stuff that I wrote when I lived in Los Angeles.
                          It's a little dated now. But I think it has a solid beat.~";
                      'name':
                          return AskForNameOldNick();
                      'bum', 'ed', 'eddie':
                          "~You mean the old bum that used to live here? He died before I left town. I helped him out when I could.~";
                      'time', 'machine', 'note', 'notes': "You better keep that bit of information to yourself.";
                      'nancy', 'punk':
                          "~Nancy? I haven't thought about her in forever. Do you even know her?
                          She always said that she was going to New York. Wanted to model.
                          Never saw her after I left though.~";
                      'nick', 'biker', 'himself', 'him', 'dude', 'man', 'artist':
                          "~I've had the shop now for almost 25 years. But I started inking people after I got
                          back from Los Angeles, around 30 years ago, when I started riding with the Outlaws.~";
                      'outlaws':
                          "~They're a rough bunch of guys. A little too hard-hitting for me, but I started tattooing because of them.~";
                      'trailer', 'park':
                          "~You don't seem to mind the trailer park. But I've cut this place in two, so I can sleep in the back.
                          I guess if I didn't live here, I'd probably live up there.~";
                      'sam':
                          "~Haven't seen Sam in a while. Last time I checked, he moved in with you.~";
                      'scientist':
                          "~No one like that has been in here.~";
                      'mark', 'attendant':
                          "~Mark's cool enough, but he's a slacker afraid of the ink.~";
                      'tom',  'guy':
                          if (self.askAboutTomTwice)
                              "~Like I said, he doesn't get it.~";
                          if (self.askAboutTom) {
                              self.askAboutTomTwice = true;
                              "~He doesn't get it. The Taurid meteor stream always happens this time of year. Tom would mistake it for sure.~";
                          }
                          self.askAboutTom = true;
                          mapleRoad.exploredTown = true;
                          "~You know, sometimes I could just throttle Tom. And at other times, he just cracks me up.
                          But I've gotten into it with him. I've seen him think a meteor shower is a UFO invasion. Crazy.~";
                      'meteor', 'meteors', 'shower', 'showers', 'taurid', 'stream':
                          "~Do you know about the Taurid meteor stream? It's also called the Halloween fireballs.
                          On a clear night, they can light up the sky - something to see.~";
                      'school', 'schooling':
                          "~School? That was never my thing unless it was art class.
                          I remember when I was a kid, I'd have fun drawing. I even did it in my spare time.~";
                      'college':
                          "~Yeah. I missed out on college, but I never wanted to go. I think I did a lot
                          better for myself and was able to open this shop by the mid-90s.~";
                      'gas', 'station':
                          "~Jerry practically runs that place now. The owner gave him full control.
                          I hear he even picks up a few night shifts just to cover things. He's
                          busting his hump over there.~";
                      'convenience', 'drug', 'store':
                          "~It's strange seeing Amy over there after all these years. Time passes and all, but still, a person should move on. It must be like 'Groundhog Day' for her.~";
                      'madame', 'sorra', 'gypsy', 'fortune-teller', 'fortune', 'teller':
                          "~I've heard a lot of things about her over the years. None of it's probably true,
                          but she has lived longer than any of us.~";
                      'work', 'job', 'shop', 'place', 'business':
                          "~I started inking people almost 30 years ago. It doesn't seem that long though.
                          After things cooled down with the Outlaws, I opened this shop. Been doing good for 20 years now,
                          but after Melville collapsed, I hope I don't have to shut my doors.~";
                      'tattoo', 'tatoo', 'tattoos', 'tatoos', 'tattoing', 'tatoing', 'ink', 'inking', 'tat', 'tats':
                          "~I've been doing it for around 30 years now. I think I've learned my art.
                          If you're looking for something. Let me know.~";
                      'vest', 'colors', 'club':
                          "~I use to ride. Had some extra money after L.A., so I bought a bike. Rode with
                          the Outlaws for a while. They got me into tattooing.~";
                      'magazine', 'mag':
                          "~Oh, some great stuff in here. I'm reading an article about Bob Tyrrell.
                          Has some awesome photos of his work. Now he can ink.~";
                      'bob', 'tyrrell':
                          "~Great artist, he is. Out of Detroit, but he travels all over.";
                      'jerry':
                          "~The guy's great. Funny too. Stops in here now and then. I've inked him.
                          And he works too hard over at the station. I've told him he should open his own
                          shop, but he seems happy over there.~";
                      'bus':
                          "~Never take it. I still have a bike if I need to go anywhere.~";
                      'melville', 'melvill':
                          "~Melville shuttered its factories, but most people had left by then. Our town tried hanging on, we even kept it going for a bit, but with the Tavern closing, things have been bleak.~";
                      'springfield':
                          "~Springfield is the only thing keeping this town going. Most of my customers come from there.
                          No one around here wants to be inked anymore.~";
                      'yukypah', 'heef', 'statue':
                          "~That statue in the park? It's a shame people keep spray painting it. I know it's hard
                          for the city to keep clean, and it's just an extra cost they don't need to pay.~";
                      'ufo', 'ufos', 'invasion':
                          if (self.askAboutUFOs) "~I don't believe in them. Why is it crazy people always do.~";
                          self.askAboutUFOs = true;
                          "~Don't tell me you're with Tom on that. He's a nut. Don't believe a word he says.
                          He's always going on about aliens. Drives me crazy.~";
                      'alien', 'aliens':
                          "~People are always talking 'bout them nowadays. But with everybody having a camera,
                          why haven't they caught one on video?~";
                      'diner':
                          "~That place is only ten years old. Doesn't look it because they don't take care of it.
                          It's a greasy little spoon that lives up to its name.~";
                      'mirror':
                          "~Go big or stay home, right? I love it. It's a great way to show off my work when I'm done.~";
                      'partition', 'section', 'wall', 'drywall':
                          "~I think I did a pretty good job. Makes for a nice bedroom in back.
                          I finished it myself, putting up the mirror.~";
                      'bedroom', 'bed', 'back':
                          "~Yeah. I sleep in the back. Built my own bedroom. It's not that big, but I don't have to pay rent. You know, other than the shop.~";
                      'industry':
                          "~There are a lot of people in the music industry that will screw you over. There's just too much money to be made.~";
                      'me', 'self', 'yourself':
                          "~I don't know you well. You don't stick out. Not like Tom.~";
                      'him', 'himself', 'her', 'herself', 'them':
                          "At the moment, even the simplest questions are confusing.";
                      'covid', 'bug', 'corona', 'coronavirus', 'virus': "~I don't want to talk about the whole COVID thing.~";
                      default:
                          return OldNickResponse();
                  }
              Tell:
                  wn = consult_from;
                  w1 = NextWord();
                  switch(w1) {
                      'hi', 'hello', 'hola', 'greetings':
                          <<Hello self>>;
                      'yes', 'please', 'ok':
                          return AnswerYesOldNick();
                      'no':
                          return AnswerNoOldNick();
                      'good':
                          "~Always glad to hear.~";
                      'bad':
                          "~Times can be tough. Sorry to hear.~";
                      'time', 'machine', 'note', 'notes', 'house', 'abandoned':
                          "He's preoccupied and doesn't care.";
                      'him', 'himself', 'her', 'herself', 'them':
                          "At the moment, even the simplest statements are confusing.";
                      'sorry':
                          "~Why be like that. Keep a stiff upper lip.~";
                      'thanks', 'thank':
                          if (self.askAboutTom) "~Glad I could help.~";
                          "~If you say so.~";
                      'goodbye', 'goodby', 'good-bye', 'bye', 'cheerio': "~Have a good night.~";
                      'mothership':
                          if (self.askAboutTom) "~Are you with Tom on this or something? I told you. It's a meteor shower.~";
                          "~Are you with Tom on this or something? I've heard that story too many times.~";
                      'evict', 'eviction', 'sam', 'trailer', 'me', 'self', 'yourself':
                          if (self.toldEvict) "You've already told him about that.";
                          self.toldEvict = true;
                          self.tellAboutEviction = true;
                          "You tell him the manager found out Sam is living there with his wife.^
                          ^~Oh, man. It sounds like you screwed up. I don't know. Your manager is hard-headed. I think you're going to have to move on.~";
                      'tom':
                          if (mapleRoad.firstTime) "~Tom makes me laugh at times. He's really out there.~";
                          "You tell him Toms freaking out down the street.^
                          ^~What's new? He's a wreck. And he's hoping to find something that's not out there.
                          It's probably a meteor shower, I've seen him do it before. He's not sharp.~";
                      'meteor', 'meteors', 'shower', 'showers', 'taurid', 'stream':
                          "You tell him you've never seen it.^
                          ^~Beautiful really. I've been around long enough to see it more than once.~";
                      'covid', 'bug', 'corona', 'coronavirus', 'virus': "~I don't want to hear about the whole COVID thing.~";
                      default:
                          "~Keep it to yourself. I'm not worried about it.~";
                  }
          ],
          orders [;
              Give:
                  if (noun == tattooShopBikerTattoos) return AskBikerForTattoo();
              Hello:
                  <<Hello self>>;
              Strong: "The biker pretends he never heard that.";
              default:
                  "The biker pays no attention to you, leafing through his magazine.";
          ],
          askAboutComplex false,
          nameFirstTime true,
          askForTattoo false,
          askAboutTattoos false,
          askAboutMusic false,
          askAboutUFOs false,
          askAboutLA false,
          askAboutClub false,
          askAboutTom false,
          askAboutTomTwice false,
          askAboutTavern false,
          lookingUp false,
          askNickClothes false,
          dontKillAskNickClothes false,
          oldNickEveningTime false,
          toldEvict false,
          tellAboutEviction false,
    has   animate male concealed;

  [ OldNickResponse;
        "~Can't help you there, maybe next time.~";
  ];

  [ AskBikerForTattoo;
        if (tattooShopNick.askForTattoo) "~If you have the cash, then fork it over.~";
        tattooShopNick.askForTattoo = true;
        "~The cheapest one I do is for 50 bucks. And that's for a simple rose. If you want something cool, it's gonna cost at least 200.~";
  ];

  [ AskForNameOldNick;
        if (tattooShopNick.nameFirstTime) {
            tattooShopNick.nameFirstTime = false;
            "~Come on. Are you pulling my leg? You know me. It's Nick.~";
        }
        "~You're not even funny now.~";
  ];

  [ AnswerYesOldNick;
        if (tattooShopNick.askNickClothes) {
            if (tattooShopNick.oldNickEveningTime) "~Give it a little while, the cold will set in.~";
            "~The temperture is going to drop anyways. You'll be fine.~";
        }
        if (self.tellAboutEviction) "~No really. You might as well move on like just about everybody else in this town.~";
        "~I won't argue the point.~";
  ];

  [ AnswerNoOldNick;
        if (tattooShopNick.askNickClothes) {
            if (tattooShopNick.oldNickEveningTime) "~Yeah, I guess it's cooler outside than I thought.~";
            "~Yeah, I guess the tempurture is going to drop.~";
        }
        if (self.tellAboutEviction) "~Look. I've been around the block. That guy doesn't need you. He's going to kick you to the curb.~";
        "~If you say so.~";
  ];
