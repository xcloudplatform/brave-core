/* Copyright (c) 2023 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at https://mozilla.org/MPL/2.0/. */

#include "brave/components/brave_ads/core/internal/account/issuers/issuers_url_request_builder_util.h"

#include "base/strings/stringprintf.h"
#include "brave/components/brave_ads/core/internal/account/confirmations/confirmation_constants.h"

namespace brave_ads {

std::string BuildIssuersUrlPath() {
  return base::StringPrintf("/v%d/issuers", kConfirmationServerVersion);
}

}  // namespace brave_ads
