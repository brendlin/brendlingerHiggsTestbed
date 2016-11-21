#if ! defined brendlingerHiggsTestbed_MESSAGING
#define brendlingerHiggsTestbed_MESSAGING

// 0: ABORT, 1: FATAL, 2: ERROR, 3: WARNING, 4: INFO, 5: DEBUG, 6: VERBOSE
#define MSG_LVL 4


#include <iostream>
#include <cstdlib>
#include <string>

#define MSG_MESSAGE( msgLvlNr, msgLvlName, msgText, color )   { \
    if (MSG_LVL >= msgLvlNr ) {					\
      std::string fileNameAll = __FILE__;				\
      std::string fileNamePrint = fileNameAll.substr( fileNameAll.find_last_of("/")+1 ); \
      std::cout << " \033[0;"						\
		<< color<<"m"						\
		<< fileNamePrint << ":"					\
		<< __LINE__ << ":"					\
		<< msgLvlName<<": "					\
		<< msgText						\
		<< "\033[0m"						\
		<< std::endl;						\
    }									\
  }

#define MSG_VERBOSE( msgText ) { MSG_MESSAGE( 6, "VERBOSE", msgText, 0 ); }
#define MSG_DEBUG( msgText )   { MSG_MESSAGE( 5, "DEBUG",   msgText, 0 ); }
#define MSG_INFO( msgText )    { MSG_MESSAGE( 4, "INFO",    msgText, 0 ); }
#define MSG_GREEN( msgText )   { MSG_MESSAGE( 4, "INFO",    msgText, 32 ); }
#define MSG_WARNING( msgText ) { MSG_MESSAGE( 3, "WARNING", msgText, 33 ); }
#define MSG_ERROR( msgText )   { MSG_MESSAGE( 2, "ERROR",   msgText, 31 ); }
#define MSG_FATAL( msgText )   { MSG_MESSAGE( 1, "FATAL",   msgText, 41 ); }

#define MSG_ABORT( msgText )   { MSG_MESSAGE( 0, "ABORT",   msgText, 45 ); std::abort(); }

#define MSG_INPUT( msgText, msgOutput ) {				\
  std::string fileNameAll = __FILE__;					\
  std::string fileNamePrint = fileNameAll.substr( fileNameAll.find_last_of("/")+1 ); \
  std::cout << " "							\
	    << fileNamePrint << ":"					\
	    << __LINE__ << ":"						\
	    << "INPUT: "						\
	    << msgText							\
	    << ": ";							\
  std::cin  >> msgOutput;						\
  }

#endif // brendlingerHiggsTestbed_MESSAGING
