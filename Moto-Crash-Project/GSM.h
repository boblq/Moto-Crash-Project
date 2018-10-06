/*
   GSM class
   All functions for use GSM module
*/

class GSMModule {
  private:

  public:

    // Activate GSM module and SIM
    void activateSIM();

    // Callback for received SMS from external service
    void receivedSMS();

    // Send SMS to phone number
    void sendSMSToPhoneNumber(const String &phone,
                              const String &textString);
};
