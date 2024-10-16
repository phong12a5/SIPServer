#ifndef SIP_MESSAGE_HPP
#define SIP_MESSAGE_HPP

#ifdef __linux__
#include <netinet/in.h>
#elif defined _WIN32 || defined _WIN64
#include <WinSock2.h>
#endif

#include <iostream>

class SipMessage
{
public:

    SipMessage();
    SipMessage(std::string message);

	void setType(std::string value);
	void setHeader(std::string value);
	void setVia(std::string value);
	void setFrom(std::string value);
	void setTo(std::string value);
	void setCallID(std::string value);
	void setCSeq(std::string value);
	void setContact(std::string value);
	void setReplaces(std::string value);
	void setContentLength(std::string value);
    void setContentType(std::string value);


	std::string getType() const;
	std::string getHeader() const;
	std::string getVia() const;
	std::string getFrom() const;
	std::string getFromNumber() const;
	std::string getTo() const;
	std::string getToNumber() const;
	std::string getCallID() const;
	std::string getCSeq() const;
	std::string getContact() const;
	std::string getContactNumber() const;
	std::string getReferToNumber() const;
	std::string getContentLength() const;
    std::string getContentType() const;

    virtual std::string toPayload();

protected:
	virtual void parse();
	bool isValidMessage() const;
    std::string extractHeader(std::string &line, std::string header) const;
	std::string extractNumber(std::string header) const;

	std::string _type;
	std::string _header;
	std::string _via;
	std::string _from;
	std::string _fromNumber;
	std::string _to;
	std::string _toNumber;
	std::string _callID;
	std::string _cSeq;
	std::string _contact;
	std::string _replaces;
	std::string _contactNumber;
	std::string _contentLength;
	std::string _contentType;
	std::string _referTo;
	std::string _referToNumber;
	std::string _referedBy;
	std::string _messageStr;
};

#endif
