// Import classes and libraries
#include "ImportClasses.h"

// Public functions
void GSMModule::activateSIM() {

  while (!LSMS.ready()) {

    delay(100);
  }

  if (debug) {

    Serial.println("Sim is activate ok");
  }

  if (LSMS.available()) {

    LSMS.flush();
  }
}

void GSMModule::receivedSMS() {
  char bufer[20];
  int c;
  String message = "";

  if (LSMS.available()) {

    LSMS.remoteNumber(bufer, 20);

    while (true) {

      c = LSMS.read();

      if (c < 0) {

        break;
      }

      Serial.print((char)c);
      message += String((char)c);
    }

    if (debug) {

      Serial.println("SMS received:");
      Serial.print("From phone number: ");
      Serial.println(bufer);
      Serial.print("Description: ");
      Serial.println();
      Serial.println("Message:");
      Serial.println(message);
    }

    LSMS.flush();
  }
}

void GSMModule::sendSMSToPhoneNumber(const String &phone, const String &textString) {

  if (LSMS.available()) {

    LSMS.flush();
  }

  String phoneClean = phone;
  phoneClean.trim();

  if (debug) {

    Serial.println("Phone:");
    Serial.println(phoneClean);
    Serial.println("Text:");
    Serial.println(textString);
  }

  char convertPhone[15];
  phoneClean.toCharArray(convertPhone, 15);
  char *finalPhone = convertPhone;

  char toChar[100];
  textString.toCharArray(toChar, 100);
  char *text = toChar;

  LSMS.beginSMS(finalPhone);
  LSMS.print(text);

  if (debug) {

    Serial.println("Sending sms with status...");
  }

  if (LSMS.endSMS()) {

    if (debug) {

      Serial.println("SMS send ok");
    }
  } else {

    if (debug) {

      Serial.println("SMS send KO");
    }
  }
}
