# Auto-Update System

Corin includes a built-in auto-update system to keep your installation up-to-date.

## Quick Commands

```bash
# Check for updates
corin --check-updates

# Update to latest version
corin --update

# Check current version
corin --version
```

## How It Works

The auto-update system:
1. Checks if you're in a git repository
2. Fetches the latest changes from GitHub
3. Stashes any local modifications
4. Pulls the latest code
5. Rebuilds Corin automatically

## Installation

### One-Line Install

```bash
curl -fsSL https://raw.githubusercontent.com/velo4705/corin-lang/main/install.sh | bash
```

This installs Corin with auto-update support enabled.

### Manual Install

```bash
git clone https://github.com/velo4705/corin-lang.git
cd corin-lang
make quick
```

## Updating

### Automatic Update

```bash
corin --update
```

This will:
- Save your local changes (git stash)
- Download the latest version
- Rebuild automatically
- Show success message

### Check for Updates

```bash
corin --check-updates
```

This checks if updates are available without installing them.

### Manual Update

If auto-update fails, you can update manually:

```bash
cd corin-lang
git pull origin main
make quick
```

## System Installation

To install Corin system-wide (accessible from anywhere):

```bash
sudo cp corin /usr/local/bin/
sudo cp corin /usr/local/bin/
sudo cp spm /usr/local/bin/
sudo cp corin-fmt /usr/local/bin/
```

Then you can run `corin` from any directory.

## Update Frequency

We recommend checking for updates:
- **Weekly** for bug fixes and improvements
- **Monthly** for new features
- **Immediately** for security updates

## Troubleshooting

### "Not in a git repository"

If you get this error, reinstall using the one-line installer:

```bash
curl -fsSL https://raw.githubusercontent.com/velo4705/corin-lang/main/install.sh | bash
```

### "Update failed"

Try manually:

```bash
cd corin-lang
git stash
git pull origin main
make quick
```

### "Build failed"

Check prerequisites:

```bash
g++ --version  # Should be C++20 compatible
make --version
git --version
```

## Version History

Check your current version:

```bash
corin --version
```

View changelog:

```bash
cat CHANGELOG.md
```

## Rollback

If an update causes issues, rollback to previous version:

```bash
cd corin-lang
git log --oneline  # Find previous commit
git checkout <commit-hash>
make quick
```

## Automatic Update Checks

Corin can check for updates automatically on startup (coming in v1.1):

```bash
# Enable auto-check (future feature)
corin config set auto-update-check true

# Disable auto-check
corin config set auto-update-check false
```

## Release Channels

Currently available:
- **main** - Stable releases (recommended)

Coming in v1.1:
- **beta** - Beta releases with new features
- **nightly** - Daily builds with latest changes

## Security

The auto-update system:
- Only updates from official GitHub repository
- Verifies git signatures (if configured)
- Preserves local changes with git stash
- Can be disabled if needed

## Disable Auto-Update

If you prefer manual updates:

```bash
# Just don't use --update flag
# Update manually with:
git pull origin main
make quick
```

## CI/CD Integration

For automated deployments:

```bash
# In your CI/CD pipeline
git clone https://github.com/velo4705/corin-lang.git
cd corin-lang
make quick
./corin --version
```

## References

- [Installation Guide](GETTING_STARTED.md)
- [Git Setup](GIT_SETUP.md)
- [Release Notes](../RELEASE_NOTES.md)
- [Changelog](../CHANGELOG.md)
