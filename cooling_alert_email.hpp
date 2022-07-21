#pragma once
#include "cooling_types.hpp"
#include "IAlert.hpp"
#include "string"
using namespace std;

class EmailAlert : public IAlert
{
   const string m_recepient;
   string m_alertmsg;

public:
   void SendAlertMsg(BreachType breachType);
   EmailAlert()
   {

   }
   EmailAlert(string mailreceipient): m_recepient(mailreceipient)
   {

   }
   ~EmailAlert()
   {
      ;
   }

   const string getMailReceipient()
   {
      return m_recepient;
   }

   string getAlertMsg()
   {
      return m_alertmsg;
   }
};
