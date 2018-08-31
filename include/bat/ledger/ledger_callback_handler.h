/* This Source Code Form is subject to the terms of the Mozilla Public
* License, v. 2.0. If a copy of the MPL was not distributed with this
* file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BAT_LEDGER_LEDGER_CALLBACK_HANDLER_
#define BAT_LEDGER_LEDGER_CALLBACK_HANDLER_

#include <string>

#include "bat/ledger/export.h"

namespace ledger {

LEDGER_EXPORT enum Result {
  OK = 0,
  ERROR = 1,
  NO_PUBLISHER_STATE = 2,
  NO_LEDGER_STATE = 3,
  INVALID_PUBLISHER_STATE = 4,
  INVALID_LEDGER_STATE = 5,
  CAPTCHA_FAILED = 6,

  TOO_MANY_RESULTS,
  NOT_FOUND,
  // some more useful result codes should go here
};

// LedgerCallbackHandler must not be destroyed if they have pending callbacks
class LEDGER_EXPORT LedgerCallbackHandler {
 public:
  virtual ~LedgerCallbackHandler() = default;

  virtual void OnLedgerStateLoaded(Result result,
                                   const std::string& data) {};
  virtual void OnLedgerStateSaved(Result result) {};

  virtual void OnPublisherStateLoaded(Result result,
                                      const std::string& data) {};
  virtual void OnPublisherStateSaved(Result result) {};

  virtual void OnURLRequestResponse(uint64_t request_id,
                                    int response_code,
                                    const std::string& response) {};

  virtual void OnPublishersListSaved(Result result) {};
};

}  // namespace ledger

#endif  // BAT_LEDGER_LEDGER_CALLBACK_HANDLER_
