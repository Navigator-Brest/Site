//
//  GetStateRequest.h
//  Site
//
//  Created by Navigator on 4/29/15.
//  Copyright (c) 2015 OrangeSoft_Brest. All rights reserved.
//

#import "K9BaseRequest.h"

@interface GetStateRequest : K9BaseRequest

@property (nonatomic, strong) NSString* user;
@property (nonatomic, strong) NSString* pass;

@end
