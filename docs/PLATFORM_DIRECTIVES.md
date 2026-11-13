# Platform Directives

Corin provides platform-specific directives for writing code that targets multiple platforms from a single codebase.

## Available Directives

### Platform Detection

```corin
#[ios]        // iOS devices
#[android]    // Android devices
#[mobile]     // iOS or Android
#[web]        // Web (WASM)
#[desktop]    // Desktop platforms (Linux, macOS, Windows)
```

## Usage

### Conditional Compilation

Write platform-specific implementations:

```corin
#[ios]
fn get_platform() -> String {
    return "iOS"
}

#[android]
fn get_platform() -> String {
    return "Android"
}

#[web]
fn get_platform() -> String {
    return "Web"
}
```

### Platform-Specific Code Blocks

Execute code only on specific platforms:

```corin
fn main() {
    #[mobile]
    {
        // This code only runs on mobile
        let camera = Camera.new()
        camera.capture()
    }
    
    #[web]
    {
        // This code only runs on web
        Window.alert("Hello!")
    }
}
```

## Native API Access

### Mobile APIs

#### Camera

```corin
#[mobile]
fn take_photo() {
    let camera = Camera.new()
    let photo = camera.capture()
    photo.save("photo.jpg")
}
```

#### GPS/Location

```corin
#[mobile]
fn get_location() {
    let gps = GPS.new()
    let loc = gps.current_location()
    print(f"Lat: {loc.lat}, Lon: {loc.lon}")
}
```

#### Sensors

```corin
#[mobile]
fn read_sensors() {
    // Accelerometer
    let accel = Accelerometer.new()
    let data = accel.read()
    
    // Gyroscope
    let gyro = Gyroscope.new()
    let rotation = gyro.read()
    
    // Compass
    let compass = Compass.new()
    let heading = compass.read()
}
```

#### Notifications

```corin
#[mobile]
fn send_notification() {
    let notif = Notification.new()
    notif.title = "Hello"
    notif.body = "Message from Corin"
    notif.send()
}
```

#### Haptics/Vibration

```corin
#[mobile]
fn vibrate() {
    Haptics.vibrate(duration: 100)
    Haptics.impact(style: "medium")
}
```

#### Storage

```corin
#[mobile]
fn use_storage() {
    let storage = Storage.new()
    storage.set("key", "value")
    let value = storage.get("key")
}
```

### Web APIs

#### Browser APIs

```corin
#[web]
fn use_browser() {
    let window = Window.current()
    window.alert("Hello!")
    
    let doc = Document.current()
    let elem = doc.get_element_by_id("myDiv")
}
```

#### Local Storage

```corin
#[web]
fn use_storage() {
    let storage = LocalStorage.new()
    storage.set("key", "value")
    let value = storage.get("key")
}
```

## Cross-Platform GUI

### Declarative UI

Build UIs that work across all platforms:

```corin
fn build_ui() -> Widget {
    return Column([
        Text("Hello, Corin!"),
        Button("Click Me", on_click: handle_click),
        Image("logo.png"),
        TextField(placeholder: "Enter text")
    ])
}
```

### Available Widgets

- `Text` - Display text
- `Button` - Clickable button
- `Image` - Display images
- `TextField` - Text input
- `Column` - Vertical layout
- `Row` - Horizontal layout
- `Stack` - Layered layout
- `ListView` - Scrollable list
- `Grid` - Grid layout

### Hot Reload

Changes to UI code are reflected immediately without restarting:

```bash
spm run --hot-reload
```

## Building for Platforms

### iOS

```bash
spm build --target ios
spm run --target ios --device "iPhone 14"
```

### Android

```bash
spm build --target android
spm run --target android --device "Pixel 7"
```

### Web (WASM)

```bash
spm build --target wasm
spm serve  # Starts local web server
```

### Desktop

```bash
spm build --target desktop
spm run
```

## Best Practices

1. **Write platform-agnostic code first**: Keep business logic separate from platform-specific code

2. **Use directives sparingly**: Only use platform directives when necessary

3. **Test on all platforms**: Ensure your app works correctly on each target platform

4. **Handle missing features gracefully**: Not all APIs are available on all platforms

```corin
fn use_camera() {
    #[mobile]
    {
        let camera = Camera.new()
        camera.capture()
    }
    
    #[web]
    {
        print("Camera not available on web")
    }
}
```

## Examples

See the `examples/` directory:
- `mobile_example.corin` - Mobile app with native APIs
- `platform_directives.corin` - Platform-specific code patterns

## Platform Support Matrix

| Feature | iOS | Android | Web | Desktop |
|---------|-----|---------|-----|---------|
| Camera | ✅ | ✅ | ⚠️ | ⚠️ |
| GPS | ✅ | ✅ | ⚠️ | ❌ |
| Sensors | ✅ | ✅ | ⚠️ | ❌ |
| Notifications | ✅ | ✅ | ✅ | ✅ |
| Storage | ✅ | ✅ | ✅ | ✅ |
| GUI | ✅ | ✅ | ✅ | ✅ |

✅ Full support  
⚠️ Limited support  
❌ Not available
