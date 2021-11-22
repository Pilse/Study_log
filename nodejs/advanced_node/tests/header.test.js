const puppeteer = require('puppeteer')
const Page = require('./page')

let page

beforeEach(async () => {
  page = await Page.build()

  await page.goto('localhost:3000')
})

afterEach(async () => {
  await page.close()
})

test('the header has the correct text', async () => {
  const text = await page.$eval('a.brand-logo', el => el.innerHTML) 

  expect(text).toEqual('Blogster')
}, 30000)

test('clicking login starts oauth flow', async () => {
  await page.click('.right a')

  const url = await page.url()

  expect(url).toMatch(/accounts\.google\.com/)
}, 30000)

test('When signed in, shows logout button', async () => {
  await page.login()

  const text = await page.$eval('a[href="/auth/logout"]', el => el.innerHTML)

  expect(text).toEqual('Logout')
}, 30000)
