// FLAMES Code

String name1="Name1", name2="Name2", commonLetters, title="FLAMES" ;

void setup() {
  Serial.begin(9600) ;  
}

void loop() {
  commonLetters = findCommon() ;
  int relation = findRelation() ;
  Serial.print("> ") ;
  Serial.println(name1) ;
  Serial.print("> ") ;
  Serial.println(name2) ;
  Serial.print("Common Letters : ") ;
  Serial.println(commonLetters) ;
  Serial.print("Relation : ") ;
  Serial.println(title[relation]) ;
  delay(100000) ;
}

String findCommon()
{
  int index=0 ;
  char cL[25] ;
  for(int i=0 ; name1[i] != '\0' ; ++i)
  {
    name1[i] = tolower(name1[i]) ;
    for(int j=0 ; name2[j] != '\0' ; ++j)
    {
      name2[i] = tolower(name2[i]) ;
      if(name1[i] == name2[j])
      {
        name1[i] = '-' ;
        name2[j] = '-' ;
        break ;
      }
    }
  }
  for(int i=0 ; name1[i] != '\0' ; ++i)
  {
    if(name1[i] != '-')
    {
      cL[index] = name1[i] ;
      ++index ;
    }
  }
  for(int i=0 ; name2[i] != '\0' ; ++i)
  {
    if(name2[i] != '-')
    {
      cL[index] = name2[i] ;
      ++index ;
    }
  }
  cL[index] = '\0' ;
  return cL ;
}

int findRelation()
{
  int len1=0, len2=0 ;
  for(int i=0 ; title[i] != '\0' ; ++i, ++len1);
  for(int i=0 ; commonLetters[i] != '\0' ; ++i, ++len2);
  return (len2-(len2/len1)*len1)-1 ;
}
