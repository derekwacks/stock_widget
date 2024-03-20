// https://github.com/aws/aws-sdk-cpp/blob/main/docs/CMake_External_Project.md
// https://github.com/aws/aws-sdk-cpp/issues/442

#include <aws/core/Aws.h>
#include <aws/cognito-idp/CognitoIdentityProviderClient.h>
#include <aws/cognito-idp/model/ListUserPoolsRequest.h>
#include <iostream>

int main(int argc, char **argv) {
    std::cout << "in main!" << std::endl;
    
    Aws::SDKOptions options;
    // Optionally change the log level for debugging.
//   options.loggingOptions.logLevel = Utils::Logging::LogLevel::Debug;
    Aws::InitAPI(options);
    int result = 0;
    
    {
        
        Aws::Client::ClientConfiguration clientConfig;
        // Optional: Set to the AWS Region (overrides config file).
        // clientConfig.region = "us-east-1";
        std::cout << "clientConfig: " << std::endl;
        std::cout << "Region: " << clientConfig.region << std::endl;
        
        Aws::CognitoIdentityProvider::CognitoIdentityProviderClient cognitoClient(clientConfig);
        
        //Aws::CognitoIdentityProvider::CognitoIdentityProviderClient client(clientConfig);

        Aws::CognitoIdentityProvider::Model::AdminInitiateAuthRequest request;

        // # # # # # # # # # # # # # # # # # # # # # #
        // "DON'T BE THAT GUY"
        Aws::String clientID = "5ivl2m4h1i1num1a73p4njdrp0";
        Aws::String userPoolID = "us-east-1_frNe6og3M";
        Aws::String userName = "myuser";
        Aws::String password = "mypassword";
        // # # # # # # # # # # # # # # # # # # # # # #

        request.SetClientId(clientID);
        request.SetUserPoolId(userPoolID);
        request.AddAuthParameters("USERNAME", userName);
        request.AddAuthParameters("PASSWORD", password);
        request.SetAuthFlow(
                Aws::CognitoIdentityProvider::Model::AuthFlowType::ADMIN_USER_PASSWORD_AUTH);


        Aws::CognitoIdentityProvider::Model::AdminInitiateAuthOutcome outcome =
                cognitoClient.AdminInitiateAuth(request);

        if (outcome.IsSuccess()) {
            std::cout << "Call to AdminInitiateAuth was successful." << std::endl;
            result = outcome.GetResult().GetSession();
        }
        else {
            std::cerr << "Error with CognitoIdentityProvider::AdminInitiateAuth. "
                    << outcome.GetError().GetMessage()
                    << std::endl;
        }


        /*
        Aws::String nextToken; // Used for pagination.
        std::vector<Aws::String> userPools;

        do {
            Aws::CognitoIdentityProvider::Model::ListUserPoolsRequest listUserPoolsRequest;
            if (!nextToken.empty()) {
                listUserPoolsRequest.SetNextToken(nextToken);
            }

            Aws::CognitoIdentityProvider::Model::ListUserPoolsOutcome listUserPoolsOutcome =
                    cognitoClient.ListUserPools(listUserPoolsRequest);

            if (listUserPoolsOutcome.IsSuccess()) {
                for (auto &userPool: listUserPoolsOutcome.GetResult().GetUserPools()) {

                    userPools.push_back(userPool.GetName());
                }

                nextToken = listUserPoolsOutcome.GetResult().GetNextToken();
            } else {
                std::cerr << "ListUserPools error: " << listUserPoolsOutcome.GetError().GetMessage() << std::endl;
                result = 1;
                break;
            }


        } while (!nextToken.empty());
        std::cout << userPools.size() << " user pools found." << std::endl;
        for (auto &userPool: userPools) {
            std::cout << "   user pool: " << userPool << std::endl;
        }
        */
    }
   
    Aws::ShutdownAPI(options);
    return result;
    
}