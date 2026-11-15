"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.activate = activate;
exports.deactivate = deactivate;
const vscode_1 = require("vscode");
const node_1 = require("vscode-languageclient/node");
let client;
function activate(context) {
    console.log('Corin extension is now active!');
    // Get LSP configuration
    const config = vscode_1.workspace.getConfiguration('corin');
    const lspEnabled = config.get('lsp.enabled', true);
    if (lspEnabled) {
        // Path to LSP server executable
        const lspPath = config.get('lsp.path', '/usr/local/bin/corin-lsp');
        // Server options
        const serverOptions = {
            command: lspPath,
            args: [],
            transport: node_1.TransportKind.stdio
        };
        // Client options
        const clientOptions = {
            documentSelector: [{ scheme: 'file', language: 'corin' }],
            synchronize: {
                fileEvents: vscode_1.workspace.createFileSystemWatcher('**/.crn')
            }
        };
        // Create the language client
        client = new node_1.LanguageClient('corinLSP', 'Corin Language Server', serverOptions, clientOptions);
        // Start the client (and server)
        client.start();
        console.log('Corin LSP client started');
    }
    // Register debug adapter
    const debugProvider = new CorinDebugConfigurationProvider();
    context.subscriptions.push(vscode_1.debug.registerDebugConfigurationProvider('corin', debugProvider));
    console.log('Corin debug adapter registered');
}
function deactivate() {
    if (!client) {
        return undefined;
    }
    return client.stop();
}
/**
 * Debug configuration provider for Corin
 */
class CorinDebugConfigurationProvider {
    resolveDebugConfiguration(folder, config, token) {
        // If launch.json is missing or empty
        if (!config.type && !config.request && !config.name) {
            const editor = vscode_1.workspace.textDocuments.find(doc => doc.languageId === 'corin');
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
//# sourceMappingURL=extension.js.map