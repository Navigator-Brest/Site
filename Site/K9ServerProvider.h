//
//  K9ServerProvider.h
//  knizniki
//
//  Created by Sania on 18.03.14.
//  Copyright (c) 2014 Orangesoft. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "K9ServerManager.h"
#import "K9ServerCache.h"

// request
#import "GetStateRequest.h"
#import "SetActiveRequest.h"
#import "SetAccessRequest.h"
#import "AuthorizationRequest.h"

// response
#import "GetStateResponse.h"
#import "SetActiveResponse.h"
#import "SetAccessResponse.h"
#import "AuthorizationResponse.h"

// info
#import "DomainData.h"
#import "AuthData.h"

//#define BOOKS_ON_PAGE   10
#define UPDATE_TIME_STEP_MIN    1.0f /*seconds*/
#define UPDATE_TIME_STEP        10.0f /*seconds*/

// Errors
#define ERROR_FIELD_TITLE       @"error"
#define ERROR_FIELD_ERRORS      @"errors"
#define ERROR_FIELD_MESSAGE     @"message"
#define INTERNET_NOT_AVAILABLE_SHOW_COUNT    3
#define INTERNET_NOT_AVAILABLE_IGNORE_COUNT  10
#define INVALID_TOKEN_STATUS    401
#define INVALID_SMS_CODE        406

static NSString* K9ServerProvider_InvalidToken_Notification = @"K9ServerProvider_InvalidToken_Notification";

@interface K9ServerProvider : NSObject
{
    NSTimeInterval m_timeForNextUpdate;
    dispatch_queue_t m_providerQueue;
    BOOL m_canTryRestore;
    BOOL m_needAutoRestore;
}

@property (nonatomic, strong) NSString* m_phone;
@property (nonatomic, strong) NSString* token;
@property (nonatomic, strong) NSString* confirmation_token;

+ (K9ServerProvider*)shared;

- (void)downloadContent:(NSString*)contentURL progress:(K9DownloadFileProgressBlock)progress completed:(K9DownloadFileFinishBlock)completed;

+ (BOOL)showServerError:(NSError*)error;                                                      // MultiThread safe
+ (BOOL)showServerError:(NSError*)error withDelegate:(id<UIAlertViewDelegate>)delegate;       // MultiThread safe

+ (NSString*)fileNameFromURL:(NSString*)url;
+ (NSString*)fontsDirectory;

- (void)setActive:(SetActiveRequest*)request completed:(void(^)(SetActiveResponse* result, NSError* error))completed;
- (void)setAccess:(SetAccessRequest*)request completed:(void(^)(SetAccessResponse* result, NSError* error))completed;
- (void)getStatus:(GetStateRequest*)request  completed:(void(^)(GetStateResponse* response, NSError* error))completed;

- (void)authorizationWithLogin:(NSString*)login password:(NSString*)password completed:(void(^)(AuthorizationResponse* result, NSError* error))completed;

#pragma mark - Settings
- (void)loadSettings;
- (void)saveSettings;
- (BOOL)validateSettings;

- (NSString*)domain;
- (NSString*)siteActivePath;
- (NSString*)userAccessPath;
- (NSString*)currentStatePath;
- (NSString*)authorizationPath;
- (NSString*)login;
- (NSString*)password;
- (BOOL)autologin;
- (void)setDomain:(NSString*)path;
- (void)setSiteActivePath:(NSString*)path;
- (void)setUserAccessPath:(NSString*)path;
- (void)setCurrentState:(NSString*)path;
- (void)setLogin:(NSString*)login;
- (void)setPassword:(NSString*)password;
- (void)setAutologin:(BOOL)autologin;
- (void)setAuthorizationPath;

@end
