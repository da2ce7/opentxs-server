/************************************************************
 *
 *  OTServer.hpp
 *
 */

/************************************************************
 -----BEGIN PGP SIGNED MESSAGE-----
 Hash: SHA1

 *                 OPEN TRANSACTIONS
 *
 *       Financial Cryptography and Digital Cash
 *       Library, Protocol, API, Server, CLI, GUI
 *
 *       -- Anonymous Numbered Accounts.
 *       -- Untraceable Digital Cash.
 *       -- Triple-Signed Receipts.
 *       -- Cheques, Vouchers, Transfers, Inboxes.
 *       -- Basket Currencies, Markets, Payment Plans.
 *       -- Signed, XML, Ricardian-style Contracts.
 *       -- Scripted smart contracts.
 *
 *  Copyright (C) 2010-2013 by "Fellow Traveler" (A pseudonym)
 *
 *  EMAIL:
 *  FellowTraveler@rayservers.net
 *
 *  BITCOIN:  1NtTPVVjDsUfDWybS4BwvHpG2pdS9RnYyQ
 *
 *  KEY FINGERPRINT (PGP Key in license file):
 *  9DD5 90EB 9292 4B48 0484  7910 0308 00ED F951 BB8E
 *
 *  OFFICIAL PROJECT WIKI(s):
 *  https://github.com/FellowTraveler/Moneychanger
 *  https://github.com/FellowTraveler/Open-Transactions/wiki
 *
 *  WEBSITE:
 *  http://www.OpenTransactions.org/
 *
 *  Components and licensing:
 *   -- Moneychanger..A Java client GUI.....LICENSE:.....GPLv3
 *   -- otlib.........A class library.......LICENSE:...LAGPLv3
 *   -- otapi.........A client API..........LICENSE:...LAGPLv3
 *   -- opentxs/ot....Command-line client...LICENSE:...LAGPLv3
 *   -- otserver......Server Application....LICENSE:....AGPLv3
 *  Github.com/FellowTraveler/Open-Transactions/wiki/Components
 *
 *  All of the above OT components were designed and written by
 *  Fellow Traveler, with the exception of Moneychanger, which
 *  was contracted out to Vicky C (bitcointrader4@gmail.com).
 *  The open-source community has since actively contributed.
 *
 *  -----------------------------------------------------
 *
 *   LICENSE:
 *   This program is free software: you can redistribute it
 *   and/or modify it under the terms of the GNU Affero
 *   General Public License as published by the Free Software
 *   Foundation, either version 3 of the License, or (at your
 *   option) any later version.
 *
 *   ADDITIONAL PERMISSION under the GNU Affero GPL version 3
 *   section 7: (This paragraph applies only to the LAGPLv3
 *   components listed above.) If you modify this Program, or
 *   any covered work, by linking or combining it with other
 *   code, such other code is not for that reason alone subject
 *   to any of the requirements of the GNU Affero GPL version 3.
 *   (==> This means if you are only using the OT API, then you
 *   don't have to open-source your code--only your changes to
 *   Open-Transactions itself must be open source. Similar to
 *   LGPLv3, except it applies to software-as-a-service, not
 *   just to distributing binaries.)
 *
 *   Extra WAIVER for OpenSSL, Lucre, and all other libraries
 *   used by Open Transactions: This program is released under
 *   the AGPL with the additional exemption that compiling,
 *   linking, and/or using OpenSSL is allowed. The same is true
 *   for any other open source libraries included in this
 *   project: complete waiver from the AGPL is hereby granted to
 *   compile, link, and/or use them with Open-Transactions,
 *   according to their own terms, as long as the rest of the
 *   Open-Transactions terms remain respected, with regard to
 *   the Open-Transactions code itself.
 *
 *   Lucre License:
 *   This code is also "dual-license", meaning that Ben Lau-
 *   rie's license must also be included and respected, since
 *   the code for Lucre is also included with Open Transactions.
 *   See Open-Transactions/src/otlib/lucre/LUCRE_LICENSE.txt
 *   The Laurie requirements are light, but if there is any
 *   problem with his license, simply remove the Lucre code.
 *   Although there are no other blind token algorithms in Open
 *   Transactions (yet. credlib is coming), the other functions
 *   will continue to operate.
 *   See Lucre on Github:  https://github.com/benlaurie/lucre
 *   -----------------------------------------------------
 *   You should have received a copy of the GNU Affero General
 *   Public License along with this program.  If not, see:
 *   http://www.gnu.org/licenses/
 *
 *   If you would like to use this software outside of the free
 *   software license, please contact FellowTraveler.
 *   (Unfortunately many will run anonymously and untraceably,
 *   so who could really stop them?)
 *
 *   DISCLAIMER:
 *   This program is distributed in the hope that it will be
 *   useful, but WITHOUT ANY WARRANTY; without even the implied
 *   warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 *   PURPOSE.  See the GNU Affero General Public License for
 *   more details.

 -----BEGIN PGP SIGNATURE-----
 Version: GnuPG v1.4.9 (Darwin)

 iQIcBAEBAgAGBQJRSsfJAAoJEAMIAO35UbuOQT8P/RJbka8etf7wbxdHQNAY+2cC
 vDf8J3X8VI+pwMqv6wgTVy17venMZJa4I4ikXD/MRyWV1XbTG0mBXk/7AZk7Rexk
 KTvL/U1kWiez6+8XXLye+k2JNM6v7eej8xMrqEcO0ZArh/DsLoIn1y8p8qjBI7+m
 aE7lhstDiD0z8mwRRLKFLN2IH5rAFaZZUvj5ERJaoYUKdn4c+RcQVei2YOl4T0FU
 LWND3YLoH8naqJXkaOKEN4UfJINCwxhe5Ke9wyfLWLUO7NamRkWD2T7CJ0xocnD1
 sjAzlVGNgaFDRflfIF4QhBx1Ddl6wwhJfw+d08bjqblSq8aXDkmFA7HeunSFKkdn
 oIEOEgyj+veuOMRJC5pnBJ9vV+7qRdDKQWaCKotynt4sWJDGQ9kWGWm74SsNaduN
 TPMyr9kNmGsfR69Q2Zq/FLcLX/j8ESxU+HYUB4vaARw2xEOu2xwDDv6jt0j3Vqsg
 x7rWv4S/Eh18FDNDkVRChiNoOIilLYLL6c38uMf1pnItBuxP3uhgY6COm59kVaRh
 nyGTYCDYD2TK+fI9o89F1297uDCwEJ62U0Q7iTDp5QuXCoxkPfv8/kX6lS6T3y9G
 M9mqIoLbIQ1EDntFv7/t6fUTS2+46uCrdZWbQ5RjYXdrzjij02nDmJAm2BngnZvd
 kamH0Y/n11lCvo1oQxM+
 =uSzz
 -----END PGP SIGNATURE-----
**************************************************************/

#ifndef __OT_SERVER_HPP__
#define __OT_SERVER_HPP__

#include <opentxs/core/OTCommon.hpp>
#include <opentxs/core/OTAccount.hpp>
#include <opentxs/core/OTAcctList.hpp>
#include <opentxs/core/OTAssetContract.hpp>
#include <opentxs/core/OTCron.hpp>
#include <opentxs/core/OTPseudonym.hpp>
#include <opentxs/core/OTTransaction.hpp>

#include <cstddef>

namespace opentxs
{

class OTAccount;
class OTAssetContract;
class ClientConnection;
class OTIdentifier;
class OTMessage;
class OTMint;
class OTPayment;
class OTServerContract;
class OTTrade;
class OTTransaction;

// Why does the map of mints use multimap instead of map?
// Because there might be multiple valid mints for the same asset type.
// Perhaps I am redeeming tokens from the previous series, which have not yet
// expired.
// Only tokens from the new series are being issued today, but tokens from the
// previous
// series are still good until their own expiration date, which is coming up
// soon.
// Therefore the server manages different mints for the same asset type, and
// since the asset
// type is the key in the multimap, we don't want to accidentally remove one
// from the list
// every time another is added. Thus multimap is employed.

class OTServer
{
public:
    static int64_t GetMinMarketScale()
    {
        return __min_market_scale;
    }

    static void SetMinMarketScale(int64_t value)
    {
        __min_market_scale = value;
    }

    static int32_t GetHeartbeatNoRequests()
    {
        return __heartbeat_no_requests;
    }

    static void SetHeartbeatNoRequests(int32_t value)
    {
        __heartbeat_no_requests = value;
    }

    static int32_t GetHeartbeatMsBetweenBeats()
    {
        return __heartbeat_ms_between_beats;
    }

    static void SetHeartbeatMsBetweenBeats(int32_t value)
    {
        __heartbeat_ms_between_beats = value;
    }

    static const std::string& GetOverrideNymID()
    {
        return __override_nym_id;
    }

    static void SetOverrideNymID(const std::string& id)
    {
        __override_nym_id = id;
    }

    OTServer();
    ~OTServer();

    // Delete various dynamically allocated things such as the map of Mints,
    // and the map of asset contracts.
    void Release();

    inline bool IsFlaggedForShutdown() const
    {
        return m_bShutdownFlag;
    }

    // Obviously this will only work once the server contract has been loaded
    // from storage.
    bool GetConnectInfo(OTString& hostname, int32_t& port);

    // Trade is passed in as reference to make sure it exists.
    // But the trade MUST be heap-allocated, as the market and cron
    // objects will own it and handle cleaning it up.
    // not needed -- erase this function.
    //    bool AddTradeToMarket(OTTrade & theTrade);

    // Each asset contract has its own series of Mints
    OTMint* GetMint(const OTIdentifier& assetTypeId, int32_t seriesCount);

    // Whenever the server issues a voucher (like a cashier's cheque), it puts
    // the funds in one
    // of these voucher accounts (one for each asset type ID). Then it issues
    // the cheque from the
    // same account.
    // TODO: also should save the cheque itself to a folder, where the folder is
    // named based on the date
    // that the cheque will expire.  This way, the server operator can go back
    // later, or have a script,
    // to retrieve the cheques from the expired folders, and total them. The
    // server operator is free to
    // remove that total from the Voucher Account once the cheque has expired:
    // it is his money now.
    // OTAccount * GetVoucherAccount(const OTIdentifier & assetTypeId);
    std::shared_ptr<OTAccount> GetVoucherAccount(
        const OTIdentifier& assetTypeId);

    // When a user uploads an asset contract, the server adds it to the list
    // (and verifies the user's key against the
    // contract.) This way the server has a directory with all the asset
    // contracts that it supports, saved by their ID.
    // As long as the IDs are in the server file, it can look them up.
    // When a new asset type is added, a new Mint is added as well. It goes into
    // the mints folder.
    bool AddAssetContract(OTAssetContract& contract);
    OTAssetContract* GetAssetContract(const OTIdentifier& assetTypeId);

    bool AddBasketAccountID(const OTIdentifier& basketId,
                            const OTIdentifier& basketAccountId,
                            const OTIdentifier& basketContractId);
    bool LookupBasketAccountID(const OTIdentifier& basketId,
                               OTIdentifier& basketAccountId);

    bool LookupBasketAccountIDByContractID(const OTIdentifier& basketContractId,
                                           OTIdentifier& basketAccountId);
    bool LookupBasketContractIDByAccountID(const OTIdentifier& basketAccountId,
                                           OTIdentifier& basketContractId);

    const OTPseudonym& GetServerNym() const;

    // Loads the config file,
    // Initializes OTDB:: default storage,
    // Sets up the data folders,
    // Loads the main file,
    // Validates the server ID (for the Nym)
    void Init(bool readOnly = false);
    bool LoadConfigFile();
    void ActivateCron();

    void ProcessCron();
    bool CreateMainFile();
    bool LoadMainFile(bool readOnly = false);
    bool LoadServerUserAndContract();
    bool SaveMainFile();
    bool SaveMainFileToString(OTString& filename);
    bool ProcessUserCommand(OTMessage& msg, OTMessage& msgOut,
                            ClientConnection* connection = nullptr,
                            OTPseudonym* nym = nullptr);

    bool ValidateServerIDfromUser(OTString& serverID);
    // After EVERY / ANY transaction, plus certain messages, we drop a copy of
    // the server's reply into the Nymbox.  This way we are GUARANTEED that the
    // Nym will receive and process it. (And thus never get out of sync.)  This
    // is the function used for doing that.
    void DropReplyNoticeToNymbox(const OTIdentifier& serverId,
                                 const OTIdentifier& userId,
                                 const OTString& messageString,
                                 const int64_t& requestNum,
                                 const bool replyTransSuccess,
                                 OTPseudonym* actualNym = nullptr);

    // Note: SendInstrumentToNym and SendMessageToNym CALL THIS.
    // They are higher-level, this is lower-level.
    bool DropMessageToNymbox(const OTIdentifier& serverId,
                             const OTIdentifier& senderUserId,
                             const OTIdentifier& recipientUserId,
                             OTTransaction::transactionType transactionType,
                             OTMessage* msg = nullptr,
                             const OTString* messageString = nullptr,
                             const char* command = nullptr);

    // msg, the request msg from payer, which is attached WHOLE to the Nymbox
    // receipt. contains payment already.
    // or pass pPayment instead: we will create our own msg here (with payment
    // inside) to be attached to the receipt.
    // szCommand for passing payDividend (as the message command instead of
    // sendUserInstrument, the default.)
    bool SendInstrumentToNym(const OTIdentifier& serverId,
                             const OTIdentifier& senderUserId,
                             const OTIdentifier& recipientUserId,
                             OTMessage* msg = nullptr,
                             const OTPayment* payment = nullptr,
                             const char* command = nullptr);

    // msg, the request msg from payer, which is attached WHOLE to the Nymbox
    // receipt. contains payment already.
    // or pass pPayment instead: we will create our own msg here (with payment
    // inside) to be attached to the receipt.
    bool SendMessageToNym(const OTIdentifier& serverId,
                          const OTIdentifier& senderUserId,
                          const OTIdentifier& recipientUserId,
                          OTMessage* msg = nullptr,
                          const OTString* messageString = nullptr);

    void UserCmdCheckServerID(OTPseudonym& nym, OTMessage& msgIn,
                              OTMessage& msgOut);
    void UserCmdCheckUser(OTPseudonym& nym, OTMessage& msgIn,
                          OTMessage& msgOut);
    void UserCmdSendUserMessage(OTPseudonym& nym, OTMessage& msgIn,
                                OTMessage& msgOut);
    void UserCmdSendUserInstrument(OTPseudonym& nym, OTMessage& msgIn,
                                   OTMessage& msgOut);
    void UserCmdGetRequest(OTPseudonym& nym, OTMessage& msgIn,
                           OTMessage& msgOut);
    void UserCmdGetTransactionNum(OTPseudonym& nym, OTMessage& msgIn,
                                  OTMessage& msgOut);
    void UserCmdIssueAssetType(OTPseudonym& nym, OTMessage& msgIn,
                               OTMessage& msgOut);
    void UserCmdIssueBasket(OTPseudonym& nym, OTMessage& msgIn,
                            OTMessage& msgOut);
    void UserCmdGetBoxReceipt(OTPseudonym& nym, OTMessage& msgIn,
                              OTMessage& msgOut);
    void UserCmdDeleteUser(OTPseudonym& nym, OTMessage& msgIn,
                           OTMessage& msgOut);
    void UserCmdDeleteAssetAcct(OTPseudonym& nym, OTMessage& msgIn,
                                OTMessage& msgOut);
    void UserCmdCreateAccount(OTPseudonym& nym, OTMessage& msgIn,
                              OTMessage& msgOut);
    void UserCmdNotarizeTransactions(OTPseudonym& nym, OTMessage& msgIn,
                                     OTMessage& msgOut);
    void UserCmdGetNymbox(OTPseudonym& nym, OTMessage& msgIn,
                          OTMessage& msgOut);
    // Deprecated (replaced by UserCmdGetAccountFiles)
    void UserCmdGetInbox(OTPseudonym& nym, OTMessage& msgIn, OTMessage& msgOut);
    // Deprecated (replaced by UserCmdGetAccountFiles)
    void UserCmdGetOutbox(OTPseudonym& nym, OTMessage& msgIn,
                          OTMessage& msgOut);
    // Deprecated (replaced by UserCmdGetAccountFiles)
    void UserCmdGetAccount(OTPseudonym& nym, OTMessage& msgIn,
                           OTMessage& msgOut);
    // This combines GetInbox, GetOutbox, and GetAccount.
    void UserCmdGetAccountFiles(OTPseudonym& nym, OTMessage& msgIn,
                                OTMessage& msgOut);
    void UserCmdGetContract(OTPseudonym& nym, OTMessage& msgIn,
                            OTMessage& msgOut);
    void UserCmdGetMint(OTPseudonym& nym, OTMessage& msgIn, OTMessage& msgOut);
    void UserCmdProcessInbox(OTPseudonym& nym, OTMessage& msgIn,
                             OTMessage& msgOut);
    void UserCmdProcessNymbox(OTPseudonym& nym, OTMessage& msgIn,
                              OTMessage& msgOut);

    void UserCmdUsageCredits(OTPseudonym& nym, OTMessage& msgIn,
                             OTMessage& msgOut);
    void UserCmdTriggerClause(OTPseudonym& nym, OTMessage& msgIn,
                              OTMessage& msgOut);

    void UserCmdQueryAssetTypes(OTPseudonym& nym, OTMessage& msgIn,
                                OTMessage& msgOut);

    // Get the list of markets on this server.
    void UserCmdGetMarketList(OTPseudonym& nym, OTMessage& msgIn,
                              OTMessage& msgOut);

    // Get the publicly-available list of offers on a specific market.
    void UserCmdGetMarketOffers(OTPseudonym& nym, OTMessage& msgIn,
                                OTMessage& msgOut);

    // Get a report of recent trades that have occurred on a specific market.
    void UserCmdGetMarketRecentTrades(OTPseudonym& nym, OTMessage& msgIn,
                                      OTMessage& msgOut);

    // Get the offers that a specific Nym has placed on a specific market.
    void UserCmdGetNym_MarketOffers(OTPseudonym& nym, OTMessage& msgIn,
                                    OTMessage& msgOut);

    bool IssueNextTransactionNumber(OTPseudonym& nym,
                                    int64_t& transactionNumber,
                                    bool storeTheNumber = true);
    bool VerifyTransactionNumber(OTPseudonym& nym,
                                 const int64_t& transactionNumber);
    bool RemoveTransactionNumber(OTPseudonym& nym,
                                 const int64_t& transactionNumber,
                                 bool save = false);
    bool RemoveIssuedNumber(OTPseudonym& nym, const int64_t& transactionNumber,
                            bool save = false);

    // If the server receives a notarizeTransactions command, it will be
    // accompanied by a payload containing a ledger to be notarized.
    // UserCmdNotarizeTransactions will loop through that ledger,
    // and for each transaction within, it calls THIS method.
    void NotarizeTransaction(OTPseudonym& nym, OTTransaction& tranIn,
                             OTTransaction& tranOut, bool& outSuccess);
    void NotarizeTransfer(OTPseudonym& nym, OTAccount& fromAccount,
                          OTTransaction& tranIn, OTTransaction& tranOut,
                          bool& outSuccess);
    void NotarizeDeposit(OTPseudonym& nym, OTAccount& account,
                         OTTransaction& tranIn, OTTransaction& tranOut,
                         bool& outSuccess);
    void NotarizeWithdrawal(OTPseudonym& nym, OTAccount& account,
                            OTTransaction& tranIn, OTTransaction& tranOut,
                            bool& outSuccess);
    void NotarizeProcessInbox(OTPseudonym& nym, OTAccount& account,
                              OTTransaction& tranIn, OTTransaction& tranOut,
                              bool& outSuccess);
    void NotarizeProcessNymbox(OTPseudonym& nym, OTTransaction& tranIn,
                               OTTransaction& tranOut, bool& outSuccess);
    void NotarizeMarketOffer(OTPseudonym& nym, OTAccount& assetAccount,
                             OTTransaction& tranIn, OTTransaction& tranOut,
                             bool& outSuccess);
    void NotarizePaymentPlan(OTPseudonym& nym, OTAccount& depositorAccount,
                             OTTransaction& tranIn, OTTransaction& tranOut,
                             bool& outSuccess);
    void NotarizeSmartContract(OTPseudonym& nym, OTAccount& activatingAccount,
                               OTTransaction& tranIn, OTTransaction& tranOut,
                               bool& outSuccess);
    void NotarizeCancelCronItem(OTPseudonym& nym, OTAccount& assetAccount,
                                OTTransaction& tranIn, OTTransaction& tranOut,
                                bool& outSuccess);
    void NotarizeExchangeBasket(OTPseudonym& nym, OTAccount& sourceAccount,
                                OTTransaction& tranIn, OTTransaction& tranOut,
                                bool& outSuccess);
    void NotarizePayDividend(OTPseudonym& nym, OTAccount& account,
                             OTTransaction& tranIn, OTTransaction& tranOut,
                             bool& outSuccess);

private:
    typedef std::multimap<std::string, OTMint*> MintsMap;
    typedef std::map<std::string, std::string> BasketsMap;
    typedef std::map<std::string, OTAssetContract*> ContractsMap;

private:
    OTString m_strWalletFilename;
    OTString m_strConfigFilename;
    OTString m_strLogFilename;
    // Used at least for whether or not to write to the PID.
    bool m_bReadOnly;
    // If the server wants to be shut down, it can set
    // this flag so the caller knows to do so.
    bool m_bShutdownFlag;

    OTString m_strVersion;
    // A hash of the server contract
    OTString m_strServerID;
    // A hash of the public key that signed the server contract
    OTString m_strServerUserID;
    // This is the server's own contract, containing its public key and
    // connect info.
    OTServerContract* m_pServerContract;
    // This stores the last VALID AND ISSUED transaction number.
    int64_t m_lTransactionNumber;

    OTPseudonym m_nymServer;

    // The asset types supported by this server.
    ContractsMap m_mapContracts;
    // The mints for each asset type.
    MintsMap m_mapMints;
    // The list of voucher accounts (see GetVoucherAccount below for details)
    OTAcctList m_VoucherAccts;
    // maps basketId with basketAccountId
    BasketsMap m_mapBaskets;
    // basket issuer account ID, which is *different* on each server, using the
    // Basket Currency's ID, which is the *same* on every server.)
    // Need a way to look up a Basket Account ID using its Contract ID
    BasketsMap m_mapBasketContracts;

    OTCron m_Cron; // This is where re-occurring and expiring tasks go.

    static int64_t __min_market_scale;

    static int32_t __heartbeat_no_requests;
    static int32_t __heartbeat_ms_between_beats;

    // The Nym who's allowed to do certain commands even if they are turned off.
    static std::string __override_nym_id;
    // Are usage credits REQUIRED in order to use this server?
    static bool __admin_usage_credits;
    // Is server currently locked to non-override Nyms?
    static bool __admin_server_locked;

    static bool __cmd_usage_credits;
    static bool __cmd_issue_asset;
    static bool __cmd_get_contract;
    static bool __cmd_check_server_id;

    static bool __cmd_create_user_acct;
    static bool __cmd_del_user_acct;
    static bool __cmd_check_user;
    static bool __cmd_get_request;
    static bool __cmd_get_trans_num;
    static bool __cmd_send_message;
    static bool __cmd_get_nymbox;
    static bool __cmd_process_nymbox;

    static bool __cmd_create_asset_acct;
    static bool __cmd_del_asset_acct;
    static bool __cmd_get_acct;
    static bool __cmd_get_inbox;
    static bool __cmd_get_outbox;
    static bool __cmd_process_inbox;

    static bool __cmd_issue_basket;
    static bool __transact_exchange_basket;

    static bool __cmd_notarize_transaction;
    static bool __transact_process_inbox;
    static bool __transact_transfer;
    static bool __transact_withdrawal;
    static bool __transact_deposit;
    static bool __transact_withdraw_voucher;
    static bool __transact_deposit_cheque;
    static bool __transact_pay_dividend;

    static bool __cmd_get_mint;
    static bool __transact_withdraw_cash;
    static bool __transact_deposit_cash;

    static bool __cmd_get_market_list;
    static bool __cmd_get_market_offers;
    static bool __cmd_get_market_recent_trades;
    static bool __cmd_get_nym_market_offers;

    static bool __transact_market_offer;
    static bool __transact_payment_plan;
    static bool __transact_cancel_cron_item;
    static bool __transact_smart_contract;
    static bool __cmd_trigger_clause;
};

} // namespace opentxs

#endif // __OT_SERVER_HPP__
