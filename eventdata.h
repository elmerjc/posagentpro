#ifndef EVENT_DATA_H
#define EVENT_DATA_H

#include <cstring>
#include <functional>
#include <map>
#include <string>

enum EventDataType { STR, INT, DOUBLE, BOOLEAN, JSON, NONE };

class EventData {
private:

  std::string strdata;
  int intdata;
  double doubledata;
  bool booldata;
  int _sender;
  std::string _name;

  EventDataType type;

public:

  std::string name() {return _name;};
  int sender() {return _sender;};
  int get_int() {return intdata;};

  EventData(std::string name, int sender_id = 0) {
    _sender = sender_id;
    type = NONE;
    _name = name;
  }
  EventData(std::string name, std::string &_strdata, bool json, int sender_id = 0) {
    _sender = sender_id;
    strdata = _strdata;
    type = json ? JSON : STR;
    _name = name;
  }

  EventData(std::string name, int _intdata, int sender_id) {
    _sender = sender_id;
    intdata = _intdata;
    type = INT;
    _name = name;
  }

  EventData(std::string name, double _doubledata, int sender_id = 0) {
    _sender = sender_id;
    doubledata = _doubledata;
    type = DOUBLE;
    _name = name;
  }

  EventData(std::string name, bool _booldata, int sender_id = 0) {
    _sender = sender_id;
    booldata = _booldata;
    type = BOOLEAN;
    _name = name;
  }
};

#endif // EVENT_DATA_H