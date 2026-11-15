import * as path from 'path';
import { workspace, ExtensionContext, debug, DebugConfiguration, WorkspaceFolder, CancellationToken, ProviderResult } from 'vscode';
import {
    LanguageClient,
    LanguageClientOptions,
    ServerOptions,
    TransportKind
} from 'vscode-languageclient/node';

let client: LanguageClient;

export function activate(context: ExtensionContext) {
    console.log('Corin extension is now active!');

    // Get LSP configuration
    const config = workspace.getConfiguration('corin');
    const lspEnabled = config.get<boolean>('lsp.enabled', true);
    
    if (lspEnabled) {
        // Path to LSP server executable
    const lspPath = config.get<string>('lsp.path', '/usr/local/bin/corin-lsp');
        
        // Server options
        const serverOptions: ServerOptions = {
            command: lspPath,
            args: [],
            transport: TransportKind.stdio
        };

        // Client options
        const clientOptions: LanguageClientOptions = {
            documentSelector: [{ scheme: 'file', language: 'corin' }],
            synchronize: {
                fileEvents: workspace.createFileSystemWatcher('**/.crn')
            }
        };

        // Create the language client
        client = new LanguageClient(
            'corinLSP',
            'Corin Language Server',
            serverOptions,
            clientOptions
        );

        // Start the client (and server)
        client.start();
        
        console.log('Corin LSP client started');
    }

    // Register debug adapter
    const debugProvider = new CorinDebugConfigurationProvider();
    context.subscriptions.push(
        debug.registerDebugConfigurationProvider('corin', debugProvider)
    );

    console.log('Corin debug adapter registered');
}

export function deactivate(): Thenable<void> | undefined {
    if (!client) {
        return undefined;
    }
    return client.stop();
}

/**
 * Debug configuration provider for Corin
 */
class CorinDebugConfigurationProvider {
    resolveDebugConfiguration(
        folder: WorkspaceFolder | undefined,
        config: DebugConfiguration,
        token?: CancellationToken
    ): ProviderResult<DebugConfiguration> {
        // If launch.json is missing or empty
        if (!config.type && !config.request && !config.name) {
            const editor = workspace.textDocuments.find(doc => doc.languageId === 'corin');
            if (editor) {
                config.type = 'corin';
                config.name = 'Launch';
                config.request = 'launch';
                config.program = editor.fileName;
                config.stopOnEntry = false;
            }
        }

        if (!config.program) {
            return undefined;
        }

        return config;
    }
}

